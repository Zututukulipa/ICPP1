#ifndef DBAPI_H
#define DBAPI_H



#include"platform.h"
#include <string>
#include<functional>
#include<fstream>
#include <vector>

// Typ datového pole
enum struct FieldType {
	Integer,
	Double,
	String,
	Field
};

// Polymorfní datovı objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhraní vyhovuje základním typùm int, double, string; pro typ „field“ je rozhraní rozšíøeno
class DLL_SPEC Object {
public:
	Object() = default;
	virtual ~Object();

	// Gettery a settery podle typu
	// Jejich funkce je definována jen v pøípadì, e aktuální objekt je odpovídajícího typu
	// Automatické konverze v základním API nejsou vyadovány

	virtual std::string getString() const;
	virtual void setString(std::string aValue);

	virtual int getInt() const;
	virtual void setInt(int aValue);

	virtual double getDouble() const;
	virtual void setDouble(double aValue);

	// Vrací true, pokud aktuální objekt pøedstavuje danı typ
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

// Objekt popisující sloupeèek „field“
class DLL_SPEC FieldObject : public Object {
public:
	std::string name;
	FieldType type;
	FieldObject();
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}

	bool isType(FieldType compType) const override;

	// Název sloupeèku
	std::string getName() const { return name; }
	// Typ sloupeèku
	FieldType getType() const { return type; }
};


// Rozhraní iterátoru (select)
class DLL_SPEC Iterator {
public:
	virtual ~Iterator();

	// Posun na další øádek (vrací true, pokud je iterátor platnı; logika podle Java Iterator)
	virtual bool moveNext();
	// Vrací pole Object* obsahující data øádku
	virtual Object** getRow() = 0;
	// Vrací interní rowId aktuálního øádku
	virtual int getRowId() = 0;
	// Uzavøe iterátor (dealokuje pamìové prostøedky)
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
	// Vloení nového øádku do tabulky (pole Object* (pro jednotlivé hodnoty sloupeèkù))
	void insert(Object** row);
	// Smazání vyrabného øádku z tabulky
	void remove(int rowid);

	// Select – vytvoøí iterátor k procházení tabulky
	Iterator* select();

	// Commit – pøenese zmìny z pamìti do datovıch souborù
	void commit();

	// Uzavøe tabulku (dealokuje pamìové prostøedky)
	void close();

	// Vrací poèet øádkù v tabulce
	int getRowCount() const;

	// Vrací pole FieldObject* popisující sloupeèky tabulky
	FieldObject** getFields() const;

	void setFields(FieldObject** aFields);

	// Vrací poèet sloupeèkù
	int getFieldCount() const;

	//Nastavuje poèet sloupcù
	void setFieldCount(int aFieldCount);

	//Vrací jméno databáze
	std::string getDatabaseName()const;

	//nastavuje jméno databáze
	void setDatabaseName(std::string aDatabaseName);

	//Vrací jméno tabulky
	std::string getTableName()const;

	//Nastavuje jméno tabulky
	void setTableName(std::string aTableName);
	void initRows();
	void freeArray();
	Object*** allocateNewArray();
	void copyToNewArray(Object*** tmp);
	void reallocateArray();


	// ============== Bonusové metody: ================
		// Select s podmínkou
	//Iterator* select(Condition* condition) { throw 0; }
	// Nalezení rowId s podmínkou
	//int findRowId(Condition* condition) { throw 0; }
	// Update – aktualizuje øádky vyhovující podmínce, aktualizaci provádí funkce „callback“
	// callback na vstupu obdrí data øádku a vrací data
	//void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }
};

// Databáze
class DLL_SPEC Db {
private:
	std::string focusedFile;
	std::string databaseName;
	std::vector<Table*> tables;
public:
	// Otevøe databázi
	static Db* open(std::string database);
	// Uzavøe databázi (dealokuje pamìové prostøedky)
	void close();

	// Vytvoøí novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otevøe existující tabulku
	Table* openTable(std::string name);
	// Otevøe tabulku (pokud neexistuje, vytvoøí automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);

	// Nastavuje jméno databáze
	void setDatabaseName(std::string aDatabaseName);

	// Vrací jméno databáze
	std::string getDatabaseName()const;

	// Alokuje objekt „int“
	static Object* Int(int value)
	{
		Object* obj = new IntObject();
		obj->setInt(value);
		return obj;
	}

	// Alokuje objekt „double“
	static Object* Double(double value)
	{
		Object* obj = new DoubleObject();
		obj->setDouble(value);
		return obj;
	}

	// Alokuje objekt „string“
	static Object* String(std::string value)
	{
		Object* obj = new StringObject();
		obj->setString(value);
		return obj;
	}

	// Alokuje objekt „field“
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
// Rozhraní definující podmínku – pouze pro bonusové metody
class DLL_SPEC Condition {
	virtual ~Condition() { }
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------

#endif // !DBAPI_H
