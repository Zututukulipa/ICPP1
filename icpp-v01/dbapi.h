// Typ datového pole
enum struct FieldType {
	Integer,
	Double,
	String,
	Field
};

// Databáze
class DLL_SPEC Db {

// Otevře databázi
static Db* open(std::string database);
    // Uzavře databázi (dealokuje paměťové prostředky)
	void close();

	// Vytvoří novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otevře existující tabulku
	Table* openTable(std::string name);
	// Otevře tabulku (pokud neexistuje, vytvoří automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);

	// Alokuje objekt „int“
	static Object* Int(int value);
        // Alokuje objekt „double“
	static Object* Double(double value);
	// Alokuje objekt „string“
	static Object* String(std::string value);
	// Alokuje objekt „field“
	static FieldObject* Field(std::string name, FieldType type);
}
// --------------------------------------------------------
// Rozhraní definující podmínku – pouze pro bonusové metody
class DLL_SPEC Condition {
	virtual ~Condition() { }
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------

// Rozhraní iterátoru (select)
class DLL_SPEC Iterator {
public:
	virtual ~Iterator();

	// Posun na další řádek (vrací true, pokud je iterátor platný; logika podle Java Iterator)
	virtual bool moveNext() = 0;
	// Vrací pole Object* obsahující data řádku
	virtual Object** getRow() = 0;
	// Vrací interní rowId aktuálního řádku
	virtual int getRowId() = 0;
	// Uzavře iterátor (dealokuje paměťové prostředky)
	virtual void close() = 0;
};

// Tabulka
class DLL_SPEC Table {
public:
	// Vložení nového řádku do tabulky (pole Object* (pro jednotlivé hodnoty sloupečků))
	void insert(Object** row);
	// Smazání vyrabného řádku z tabulky
	void remove(int rowid);

	// Select – vytvoří iterátor k procházení tabulky
	Iterator* select();

	// Commit – přenese změny z paměti do datových souborů
	void commit();

	// Uzavře tabulku (dealokuje paměťové prostředky)
	void close();

	// Vrací počet řádků v tabulce
	int getRowCount() const;

	// Vrací pole FieldObject* popisující sloupečky tabulky
	FieldObject** getFields() const;

	// Vrací počet sloupečků
	int getFieldCount() const;


	// ============== Bonusové metody: ================
        // Select s podmínkou
	Iterator* select(Condition* condition) { throw 0; }
	// Nalezení rowId s podmínkou
	int findRowId(Condition* condition) { throw 0; }
	// Update – aktualizuje řádky vyhovující podmínce, aktualizaci provádí funkce „callback“
	// callback na vstupu obdrží data řádku a vrací data
	void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }
}

// Polymorfní datový objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhraní vyhovuje základním typům int, double, string; pro typ „field“ je rozhraní rozšířeno
class DLL_SPEC Object {
public:
	Object();
	virtual ~Object();

	// Gettery a settery podle typu
	// Jejich funkce je definována jen v případě, že aktuální objekt je odpovídajícího typu
	// Automatické konverze v základním API nejsou vyžadovány

	virtual std::string getString() const;
	virtual void setString(std::string value);

	virtual int getInt() const;
	virtual void setInt(int value);

	virtual double getDouble() const;
	virtual void setDouble(double value);

	// Vrací true, pokud aktuální objekt představuje daný typ
	virtual bool isType(FieldType type) const;
};


class DLL_SPEC IntObject : public Object {
public:
	IntObject() : value(0) {}
	IntObject(int v) : value(v) {}
// …
};

class DLL_SPEC DoubleObject : public Object {
public:
	DoubleObject() : value(0.0) {}
	DoubleObject(double v) : value(v) {}
// …
};

class DLL_SPEC StringObject : public Object {
public:
	StringObject() : value("") {}
	StringObject(std::string v) : value(v) {}
// …
};

// Objekt popisující sloupeček „field“
class DLL_SPEC FieldObject : public Object {
public:
	FieldObject() {}
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}

	virtual bool isType(FieldType type) const override;

	// Název sloupečku
	std::string getName() const { return name; }
	// Typ sloupečku
	FieldType getType() const { return type; }
};

