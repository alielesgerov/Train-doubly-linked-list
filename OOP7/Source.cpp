#include<iostream>
#include<Windows.h>
#include<string>
#include<assert.h>

class Product
{
	int id;
	std::string name;
	std::string company;
	double price;
	double discount;
public:
	static int myid;
	Product() :id(0), name(""), company(""), price(0), discount(0) {};
	Product(std::string name,std::string company ,double price,double discount)
	{
		setID();
		setName(name);
		setCompany(company);
		setPrice(price);
		setDiscount(discount);
	}
	//Setter
	void setID()
	{
		this->id = ++myid;
	}
	void setName(std::string name)
	{
		this->name = name;
	}
	void setCompany(std::string company)
	{
		this->company = company;
	}
	void setPrice(double price)
	{
		this->price = price;
	}
	void setDiscount(double discount)
	{
		this->discount = discount;
	}
	//Getter
	int getID()const
	{
		return id;
	}
	std::string getName()const
	{
		return name;
	}
	std::string getCompany()const
	{
		return company;
	}
	double getPrice()const
	{
		return price;
	}
	double getDiscount()const
	{
		return discount;
	}
	double getPriceWithDiscount()const
	{
		return this->price - ((this->price * this->discount) / 100);
	}
	//Show
	void ShowProduct()const
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout << "==========================================\n";
		std::cout << "Product ID: ";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << getID() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Product Name: ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout <<getName() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Company: ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << getCompany() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Price: ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << getPrice() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Discount: ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << getDiscount() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Price With Discount: ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << getPriceWithDiscount() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	//
	friend std::ostream& operator<<(std::ostream& out, const Product& product);
};

std::ostream& operator<<(std::ostream& out, const Product& product)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	out << "==========================================\n";
	out << "Product ID: ";
	SetConsoleTextAttribute(hConsole, 12);
	out << product.getID() << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	out << "Product Name: ";
	SetConsoleTextAttribute(hConsole, 10);
	out << product.getName() << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	out << "Company: ";
	SetConsoleTextAttribute(hConsole, 10);
	out << product.getCompany() << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	out << "Price: ";
	SetConsoleTextAttribute(hConsole, 10);
	out << product.getPrice() << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	out << "Discount: ";
	SetConsoleTextAttribute(hConsole, 10);
	out << product.getDiscount() << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	out << "Price With Discount: ";
	SetConsoleTextAttribute(hConsole, 10);
	out << product.getPriceWithDiscount() << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	return out;
}

int Product::myid = 0;

template<typename T>
class Stack
{
	T* products;
	size_t size;
public:
	Stack():products(nullptr),size(0){}
	Stack(T* products, size_t size)
	{
		setSize(size);
		setProduct(products);
	}
	//Setter
	void setSize(size_t size)
	{
		this->size = size;
	}
	void setProduct(T* products)
	{
		this->products = products;
	}
	//Getter
	size_t getSize()const
	{
		return size;
	}
	T* getProduct()const
	{
		return products;
	}
	//
	void push(const T& product)
	{
		T* new_product = new T [getSize()+1];
		if (isEmpty())
		{
			for (size_t i = 0; i < getSize(); i++)
			{
				new_product[i] = products[i];
			}
		}
		delete[]products;
		new_product[getSize()] = product;
		products = new_product;
		new_product = nullptr;
		setSize(getSize() + 1);
	}
	T pop()
	{
		T temp = products[getSize() - 1];
		T* new_products = new T[getSize() - 1];
		if (isEmpty())
		{
			for (size_t i = 0; i < getSize() - 1; i++)
			{
				new_products[i] = products[i];
			}
			delete[]products;
		}
		products = new_products;
		new_products = nullptr;
		setSize(getSize() - 1);
		return temp;
	}
	void clear()
	{
		if (products != nullptr)
		{
			delete[] products;
			products = nullptr;
			size = 0;
		}
	}
	bool isEmpty()const
	{
		if (size > 0)
			return true;
		return false;
	}
	//Test
	/*void Show()const
	{
		for (size_t i = 0; i < getSize(); i++)
		{
			std::cout << products[i] << std::endl;
		}
	}*/
};
template<typename T>
class Wagon
{
	std::string no;
	int count;
	double speed;
	std::string country;
	T* products;
public:
	Wagon() :no(""),count(0), speed(0), country(""){}
	Wagon(std::string no, std::string country, double speed, Stack<T>stack)
	{
		setNO(no);
		setCountry(country);
		setSpeed(speed);
		setCount(stack.getSize());
		setProducts(stack.getProduct());
	}
	//Setter
	void setNO(std::string no)
	{
		this->no = no;
	}
	void setCountry(std::string country)
	{
		this->country = country;
	}
	void setSpeed(double speed)
	{
		this->speed = speed;
	}
	void setCount(int count)
	{
		this->count = count;
	}
	void setProducts(T* products)
	{
		this->products=(products);
	}
	//Getter
	std::string getNO()const
	{
		return no;
	}
	std::string getCountry()const
	{
		return country;
	}
	double getSpeed()const
	{
		return speed;
	}
	int getCount()const
	{
		return count;
	}
	T* getProducts()const
	{
		return products;
	}
	//
	void showProductsInfo()const
	{
		for (size_t i = 0; i < getCount(); i++)
		{
			products[i].ShowProduct();
		}
	}
	void showWagon() const
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "=======================================\n";
		std::cout << "Wagon no: ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout<< getNO() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Country: ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout<< getCountry() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Speed: ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout<< getSpeed() << " km/h" << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Product count: ";
		SetConsoleTextAttribute(hConsole, 10);
		std::cout<< getCount() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
};

template <typename T>
struct Node
{
	Node<T>* prev;
	Node<T>* next;
	Wagon<T>* current;
};

template <class T>
class Train
{
	std::string name;
	Node<T>* first;
	Node<T>* last;

public:
	Train() {}

	Train(const std::string& name, Node<T>* first, Node<T>* last)
	{
		setName(name);
		setFirst(first);
		setLast(last);
	}
	//setter
	void setName(const std::string& name)
	{
		assert(!name.empty() && "Name cant be blank");
		this->name = name;
	}
	void setFirst(Node<T>* first)
	{
		assert(first != NULL && "first cant be null");
		this->first = first;
	}
	void setLast(Node<T>* last)
	{
		assert(last != NULL && "last cant be null");
		this->last = last;
	}
	//get
	Node<T>* getWagonByNo(const std::string& no)
	{
		Node<T>* tmp = this->first;

		while (tmp != NULL)
		{
			if (tmp->current->getNO() == no)
			{
				return tmp;
			}
			tmp = tmp->next;
		}

		return NULL;
	}
	//traverse
	void forwardTraverse()
	{
		Node<T>* tmp = first;
		while (tmp != NULL)
		{
			tmp->current->showWagon();
			tmp->current->showProductsInfo();
			tmp = tmp->next;
		}
	}
	void backwardTraverse()
	{
		Node<Product>* tmp = last;
		while (tmp != NULL)
		{
			tmp->current->showWagon();
			tmp->current->showProductsInfo();
			tmp = tmp->prev;
		}
	}
	//show
	void showProductsByNo(const std::string& no)
	{
		if (this->first != NULL)
		{
			Node<T>* node = getWagonByNo(no);
			if (node)
				node->current->showProductsInfo();
		}
		return;
	}
	void showWagonByNo(const std::string& no)
	{
		if (this->first != NULL)
		{
			Node<T>* node = getWagonByNo(no);
			if (node)
				node->current->showWagon();
		}
		return;
	}
	//delete
	void deleteWagonByNo(const std::string& no)
	{
		if (this->first == NULL)
			return;

		Node<T>* node = getWagonByNo(no);

		if (node == NULL)
			return;
		else if (node->prev == NULL)
		{
			this->first = node->next;
			this->first->prev = NULL;
		}
		else if (node->next == NULL)
		{
			this->last = node->prev;
			this->last->next = NULL;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}

		delete node;
		node = NULL;
	}
	//update
	void updateSpeedByNo(const std::string& no, double speed)
	{
		if (this->first != NULL)
		{
			Node<T>* node = getWagonByNo(no);
			if (node != NULL)
				node->current->setSpeed(speed);
		}
		return;
	}
	void updateCountryByNo(const std::string& no, const std::string& country)
	{
		if (this->first != NULL)
		{
			Node<T>* node = getWagonByNo(no);
			if (node != NULL)
				node->current->setCountry(country);

		}
		return;

	}
};

int main()
{
	Product p1("SomeProduct1", "SomeCompany1", 10, 10);
	Product p2("SomeProduct2", "SomeCompany2", 15, 20);
	Product p3("SomeProduct3", "SomeCompany3", 20, 30);
	Product p4("SomeProduct4", "SomeCompany4", 25, 40);
	Product p5("SomeProduct5", "SomeCompany5", 30, 50);
	Product* products = new Product  [5]{ p1,p2,p3,p4,p5 };
	Stack<Product> stack(products, 5);
	Product* p6 = new Product("SomeProduct6", "SomeCompany6", 35, 60);
	stack.push(*p6);
	stack.pop();
	//stack.Show();
	Wagon<Product> wagon("A135","Azerbaijan",100,stack);
	Wagon<Product> wagon1("B113", "Russia", 120, stack);
	Node<Product>* first = new Node<Product>;
	first->current = new Wagon<Product>(wagon);
	first->prev = NULL;
	first->next = NULL;

	Node<Product>* last = new Node<Product>;
	last->current = new Wagon<Product>(wagon1);
	last->prev = first;
	last->prev->next = last;
	last->next = NULL;
	Train<Product> train("ED12H",first,last);
	//train.deleteWagonByNo("A135");
	//train.showProductsByNo("A135");
	//train.showWagonByNo("A135");
	//train.forwardTraverse();
	//train.updateCountryByNo("A135","germany");
	//train.updateSpeedByNo("A135", 160);
	//train.showWagonByNo("A135");
	return 0;
}