class IComparable
{
private:
public:
	IComparable() {};
	virtual ~IComparable() {};
    virtual int compareTo(IComparable* obj) const = 0;
};


