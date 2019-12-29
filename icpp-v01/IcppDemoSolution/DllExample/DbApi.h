#ifndef DBAPI_H
#define DBAPI_H



#include"platform.h"
#include <string>
#include<functional>
#include<fstream>
#include <vector>

// Typ datov�ho pole
enum struct FieldType {
	Integer,
	Double,
	String,
	Field
};

// Polymorfn� datov� objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhran� vyhovuje z�kladn�m typ�m int, double, string; pro typ �field� je rozhran� roz���eno
class DLL_SPEC Object {
public:
	Object() = default;
	virtual ~Object();

	// Gettery a settery podle typu
	// Jejich funkce je definov�na jen v p��pad�, �e aktu�ln� objekt je odpov�daj�c�ho typu
	// Automatick� konverze v z�kladn�m API nejsou vy�adov�ny

	virtual std::string getString() const;
	virtual void setString(std::string aValue);

	virtual int getInt() const;
	virtual void setInt(int aValue);

	virtual double getDouble() const;
	virtual void setDouble(double aValue);

	// Vrac� true, pokud aktu�ln� objekt p�edstavuje dan� typ
	virtual bool isType(FieldType aType) const;
};

class DLL_SPEC IntObject : public Object {
public:
	int value;
	IntObject() : value(0){}
	IntObject(int v) : value(v){}
	int getInt()const override;
	void setInt(int aValue) override;
};

class DLL_SPEC DoubleObject : public Object {
public:
	double value;
	DoubleObject() : value(0.0) {}
	DoubleObject(double v) : value(v) {}
	double getDouble() const override;
	void setDouble(double aValue) override;
};

class DLL_SPEC StringObject : public Object {
public:
	std::string value;
	StringObject() : value("") {}
	StringObject(std::string v) : value(v) {}
	std::string getString() const override;
	void setString(std::string aValue) override;
};

// Objekt popisuj�c� sloupe�ek �field�
class DLL_SPEC FieldObject : public Object {
public:
	std::string name;
	FieldType type;
	FieldObject();
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}

	bool isType(FieldType compType) const override;

	// N�zev sloupe�ku
	std::string getName() const { return name; }
	// Typ sloupe�ku
	FieldType getType() const { return type; }
};


// Rozhran� iter�toru (select)
class DLL_SPEC Iterator {
public:
	virtual ~Iterator();

	// Posun na dal�� ��dek (vrac� true, pokud je iter�tor platn�; logika podle Java Iterator)
	virtual bool moveNext();
	// Vrac� pole Object* obsahuj�c� data ��dku
	virtual Object** getRow() = 0;
	// Vrac� intern� rowId aktu�ln�ho ��dku
	virtual int getRowId() = 0;
	// Uzav�e iter�tor (dealokuje pam�ov� prost�edky)
	virtual void close() = 0;
};

// Tabulka
class DLL_SPEC Table {
private:
	std::string dbName;
	std::string name;
	int fieldCount{};
	FieldObject** fields{};
	int rowCount{};
	int rowCapacity{};
	Object*** rows{};
public:
	// Vlo�en� nov�ho ��dku do tabulky (pole Object* (pro jednotliv� hodnoty sloupe�k�))
	void insert(Object** row);
	// Smaz�n� vyrabn�ho ��dku z tabulky
	void remove(int rowid);

	// Select � vytvo�� iter�tor k proch�zen� tabulky
	Iterator* select();

	// Commit � p�enese zm�ny z pam�ti do datov�ch soubor�
	void commit();

	// Uzav�e tabulku (dealokuje pam�ov� prost�edky)
	void close();

	// Vrac� po�et ��dk� v tabulce
	int getRowCount() const;

	// Vrac� pole FieldObject* popisuj�c� sloupe�ky tabulky
	FieldObject** getFields() const;

	void setFields(FieldObject** aFields);

	// Vrac� po�et sloupe�k�
	int getFieldCount() const;

	//Nastavuje po�et sloupc�
	void setFieldCount(int aFieldCount);

	//Vrac� jm�no datab�ze
	std::string getDatabaseName()const;

	//nastavuje jm�no datab�ze
	void setDatabaseName(std::string aDatabaseName);

	//Vrac� jm�no tabulky
	std::string getTableName()const;

	//Nastavuje jm�no tabulky
	void setTableName(std::string aTableName);
	void initRows();
	void freeArray();
	Object*** allocateNewArray();
	void copyToNewArray(Object*** tmp);
	void reallocateArray();


	// ============== Bonusov� metody: ================
		// Select s podm�nkou
	//Iterator* select(Condition* condition) { throw 0; }
	// Nalezen� rowId s podm�nkou
	//int findRowId(Condition* condition) { throw 0; }
	// Update � aktualizuje ��dky vyhovuj�c� podm�nce, aktualizaci prov�d� funkce �callback�
	// callback na vstupu obdr�� data ��dku a vrac� data
	//void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }
};

// Datab�ze
class DLL_SPEC Db {
private:
	std::string focusedFile;
	std::string databaseName;
	std::vector<Table*> tables;
public:
	// Otev�e datab�zi
	static Db* open(std::string database);
	// Uzav�e datab�zi (dealokuje pam�ov� prost�edky)
	void close();

	// Vytvo�� novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otev�e existuj�c� tabulku
	Table* openTable(std::string name);
	// Otev�e tabulku (pokud neexistuje, vytvo�� automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);

	// Nastavuje jm�no datab�ze
	void setDatabaseName(std::string aDatabaseName);

	// Vrac� jm�no datab�ze
	std::string getDatabaseName()const;

	// Alokuje objekt �int�
	static Object* Int(int value)
	{
		Object* obj = new IntObject();
		obj->setInt(value);
		return obj;
	}

	// Alokuje objekt �double�
	static Object* Double(double value)
	{
		Object* obj = new DoubleObject();
		obj->setDouble(value);
		return obj;
	}

	// Alokuje objekt �string�
	static Object* String(std::string value)
	{
		Object* obj = new StringObject();
		obj->setString(value);
		return obj;
	}

	// Alokuje objekt �field�
	static FieldObject* Field(std::string name, FieldType type)
	{
		switch (type) {
		case FieldType::Integer:
			return new FieldObject(name, FieldType::Integer);
		case FieldType::Double:
			return new FieldObject(name, FieldType::Double);
		case FieldType::String:
			return new FieldObject(name, FieldType::String);
		case FieldType::Field:
			return new FieldObject(name, FieldType::Field);
		default:
			return nullptr;
		}
	}
};

// --------------------------------------------------------
// Rozhran� definuj�c� podm�nku � pouze pro bonusov� metody
class DLL_SPEC Condition {
	virtual ~Condition() { }
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------

#endif // !DBAPI_H
