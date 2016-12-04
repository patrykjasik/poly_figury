#include <iostream>
using namespace std;


/////////////////////////////////////////////////////////
class instrum {
public:
	virtual void wydaj_dzwiek() {
		cout << "cisza";
	}
	// ----wirtualny destruktor
//	virtual 
		~instrum()                                  //
	{
		cout << "Destruktor instrumentu \n";

	}
};
/////////////////////////////////////////////////////////
class skrzypce : public instrum {                         //
	char *nazwa;
public:
	// - konstruktor------------------------

	skrzypce(const char *firma)
	{
		nazwa = new char[strlen(firma) + 1];
		for (int i=0; i < strlen(nazwa); i++) 
		nazwa[i] = firma[i];
	}
	//- destruktor (wirtualny) -----------------

	~skrzypce()
	{
		cout << "Destruktor skrzypiec + ";
		delete[] nazwa;                              //
	}
	// ----------------------------

	void wydaj_dzwiek()
	{
		cout << "tirli-tirli ("
			<< nazwa << ")\n";
	}
};
/////////////////////////////////////////////////////////
class gwizdek :public instrum {                         //
public:
	void wydaj_dzwiek() {
		cout << "fiu-fiu \n";
	}
};
/////////////////////////////////////////////////////////
class gitara : public instrum {
	char *nazwa;
public:
	// - konstruktor-------------------

	gitara(const char *firma)
	{
		nazwa = new char[strlen(firma) + 1];       //
		for (int i = 0; i < strlen(nazwa); i++)
			nazwa[i] = firma[i];
	}
	//- destruktor (wirtualny) ---------------

	~gitara()
	{
		cout << "Destruktor gitary + ";
		delete[] nazwa;                                //
	}
	// --------------------------

	void wydaj_dzwiek()
	{
		cout << "brzdek-brzdek   ("
			<< nazwa << ")\n";
	}
};
/*******************************************************/
int main()
{
	cout << "Definiujemy w zapasie pamieci\n"
		"trzy instrumenty orkiestry\n  ";

	instrum *pierwszy = new skrzypce("Stradivarius");
	instrum *drugi = new gitara("Ramirez");
	instrum *trzeci = new gwizdek;                 //

	cout << "Gramy polimorficznie ! \n";

	pierwszy->wydaj_dzwiek();                         //
	drugi->wydaj_dzwiek();
	trzeci->wydaj_dzwiek();

	cout << "\nKoncert sie skonczyl, "
		"likwidujemy instrumenty\n\n";

	delete pierwszy;                                   //
	cout << "******************\n";
	delete drugi;
	cout << "******************\n";
	delete trzeci;

	system("pause");
	return 0;
}
