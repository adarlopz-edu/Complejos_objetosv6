#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Funcion para simplificar y  imprimir los resultados en diferentes casos, Declaro esta funcion aqui porque se necesita usar en la clase
void simplificarParteCompleja(int resultadoReal, int resultadoComplejo, bool division) {

    if (division == true) { // caso especial para mostrar la division
        // si la parte real es cero
        if (resultadoReal == 0) {
            cout << resultadoComplejo << 'i';
        }
        // si la parte imaginaria es cero
        if (resultadoComplejo == 0) {
            cout << resultadoReal;
        }
        // si la parte imaginaria es negativa
        else if (resultadoComplejo < 0) {
            cout << resultadoReal << resultadoComplejo << 'i';
        }
        // si la parte imaginaria es 1
        else if (resultadoComplejo == 1) {
            cout << resultadoReal << '+' << 'i';
        }
        // si la parte imaginaria es no es 0
        else {
            cout << resultadoReal << '+' << resultadoComplejo << 'i';
        }
    }
    if (division == false) {
        cout << endl << "El resultado es: ";

        // si la parte real es cero
        if (resultadoReal == 0) {
            cout << resultadoComplejo << 'i' << endl;
        }
        // si la parte imaginaria es cero
        if (resultadoComplejo == 0) {
            cout << resultadoReal << endl;
        }
        // si la parte imaginaria es negativa
        else if (resultadoComplejo < 0) {
            cout << resultadoReal << resultadoComplejo << 'i' << endl;
        }
        // si la parte imaginaria es 1
        else if (resultadoComplejo == 1) {
            cout << resultadoReal << '+' << 'i' << endl;
        }
        // si la parte imaginaria es no es 0
        else {
            cout << resultadoReal << '+' << resultadoComplejo << 'i' << endl;
        }
    }
}

// clase para un numero
class Numero {
private:
    int Real; // su parte real 
    int Complejo; // su parte compleja
    char Objeto; // objeto asignado al Numero

public:
    Numero(int real, int complejo, char objeto); // constructor
    ~Numero(); // destructor

    Numero operator+(Numero numero2) { // sobrecarga del operador +, y aqui se hace la funcion suma
        Numero resultado(Real + numero2.Real, Complejo + numero2.Complejo, 'R');
        int resultadoReal = Real + numero2.Real; // suma las partes reales
        int resultadoComplejo = Complejo + numero2.Complejo; // suma las partes complejas
        simplificarParteCompleja(resultadoReal, resultadoComplejo, false);
        return resultado;
    }

    Numero operator-(Numero numero2) { // sobrecarga del operador -, mas la funcion resta
    		Numero resultado(Real - numero2.Real, Complejo - numero2.Complejo, 'R');
    		int resultadoReal = Real - numero2.Real; // resta las partes reales
    		int resultadoComplejo = Complejo - numero2.Complejo; // resta las partes complejas
    		simplificarParteCompleja(resultadoReal, resultadoComplejo, false);
    		return resultado;
    	}

    Numero operator*(Numero numero2) { // sobrecarga del operador *, mas la funcion para multiplicar
    		Numero resultado(Real * numero2.Real - Complejo * numero2.Complejo, Real * numero2.Complejo + Complejo * numero2.Real, 'R');
    		int resultadoReal = Real * numero2.Real - Complejo * numero2.Complejo; //Algoritmo para parte real
    		int resultadoComplejo = Real * numero2.Complejo + Complejo * numero2.Real; //algoritmo para parte compleja
    		simplificarParteCompleja(resultadoReal, resultadoComplejo, false);
    		return resultado;
    	}

    Numero operator/(Numero numero2) { // sobrecarga del operador /, y la funcion para divir
    		Numero resultado(Real * numero2.Real - Complejo * numero2.Complejo, Real * numero2.Complejo + Complejo * numero2.Real, 'R');
    		int conjugadoReal = numero2.Real; //el conjugado real va a ser la parte real del denominador
    		int conjugadoComplejo = -numero2.Complejo; // elconjugado complejo es la parte compleja del denominador por -1
    
    		if (conjugadoReal == 0 && conjugadoComplejo == 0) { // si el conjugado real y el conjugado complejo es 0, error
                cout << "Error" << endl;
                return resultado;
            }
    
    		int resultadoReal = Real * conjugadoReal - Complejo * conjugadoComplejo;
    		int resultadoComplejo = Real * conjugadoComplejo + Complejo * conjugadoReal;
    		cout << endl << "El resultado es: ";
    		simplificarParteCompleja(resultadoReal, resultadoComplejo, true);
    		cout << "/";
    		int resultadoReal2 = numero2.Real * conjugadoReal - numero2.Complejo * conjugadoComplejo;
    		int resultadoComplejo2 = numero2.Real * conjugadoComplejo + numero2.Complejo * conjugadoReal;
    		return resultado;
    	}
};

// constructor para la clase 
Numero::Numero(int real, int complejo, char objeto) : Real(real), Complejo(complejo), Objeto(objeto) {
    cout << "Constructor para: " << Objeto << endl;
}

// destructor para la clase
Numero::~Numero() {
    cout << "Destruyendo (" << Objeto << ")" << endl;
}

int simplificar(int mcd, int top, int entero) {//Arreglar la simplificacion sobrecargada

    int a{}, b{}, i{};

    int o{};
    //for (o; o < 3; o++) {

    if (entero >= 1) {
        cout << "El resultado es: " << entero;
    }
    if (top == 0) {
        cout << "El resultado es 0";
    }

    if (entero > 0) {
        int r = top % mcd;
        a = max(r, mcd);
        b = min(r, mcd);

        do {
            i = b;
            b = a % b;
            a = i;
        } while (b != 0);

        a = r / i;
        b = mcd / i;

        cout << a << "/" << b << "\n";
    }
    else {
        int r = top % mcd;
        a = max(r, mcd);
        b = min(r, mcd);

        do {
            i = b;
            b = a % b;
            a = i;
        } while (b != 0);

        a = r / i;
        b = mcd / i;

        cout << endl << "El resultado es: " << a << "/" << b << endl;
        //}
    }
    return a, b;
}

// Funcion para validar el input
bool validarInput(string expresion) {
    int posicionOperador = expresion.find_first_of("+-*/"); // busca cualquier operador de los 4, y devuelve un bool

    if (posicionOperador == 0 || posicionOperador == expresion.length() - 1) { // el operador no puede estar ni al principio ni al final
        if (expresion[0] == '/') {
            cout << "Error" << endl;
            return false;
        }

        cout << "Error" << endl;
        return false;
    }

    return true;
}

// Funcion para contar la cantidad de ciertos caracteres que hay en un string
int countOccurrences(char c, string& str) {
    int count = 0;

    for (char i : str)
        if (i == c) count++;

    return count;
}

// Funcion para decodificar la expresion de entrada en partes reales e imaginarias
void Decodificador(string expresion, int numeros[], int realIndex, int complexIndex) {
    char operators[] = { '+', '-', '*', '/' };

    int totalOperators{}; // declaracion
    for (char c : operators) {
        totalOperators += countOccurrences(c, expresion); // cuenta la cantiad de operadores que hay en el string
    }

    if (totalOperators == 2) { // si el numero real es negativo
        int posicionOperador = expresion.find_first_of("+-"); // aqui busca la posicion en el string del primer operador (que es cuando el real es negativo)
        istringstream streamPrimerNumero(expresion.substr(0, posicionOperador - 1)); //si es un string convierte de la posicion 0 hasta la posicion del operador y lo convierte en un int
        streamPrimerNumero >> numeros[realIndex];

        int segundaPosicionOperador = expresion.find_first_of("+-", posicionOperador + 1); // busca la posicion del segundo operador

        cout << endl << posicionOperador << endl;
        cout << endl << segundaPosicionOperador << endl;

        if (segundaPosicionOperador != string::npos) {
            istringstream streamSegundoNumero(expresion.substr(segundaPosicionOperador));
            streamSegundoNumero >> numeros[complexIndex];
        }
        else {
            istringstream streamSegundoNumero(expresion.substr(posicionOperador + 1));
            streamSegundoNumero >> numeros[complexIndex];
        }
    }
    else { // si el numero real es positivo
        int posicionOperador = expresion.find_first_of("+-");
        istringstream streamPrimerNumero(expresion.substr(0, posicionOperador));
        streamPrimerNumero >> numeros[realIndex];

        int segundaPosicionOperador = expresion.find_first_of("+-", posicionOperador + 1);

        if (segundaPosicionOperador != string::npos) {
            istringstream streamSegundoNumero(expresion.substr(segundaPosicionOperador)); // si es un string convierte los caracteres que esten despues del operador y lo convierte en un int
            streamSegundoNumero >> numeros[complexIndex];
        }
        else {
            istringstream streamSegundoNumero(expresion.substr(posicionOperador + 1));
            streamSegundoNumero >> numeros[complexIndex];
        }

        if (posicionOperador != string::npos && expresion[posicionOperador] == '-') {
            numeros[complexIndex] = -numeros[complexIndex];
        }
    }
}

// Funcion para tomar expresiones de entrada y realizar operaciones con numeros complejos
void Input(string expresion1, string expresion2, int numeros1[2], int numeros2[2], int tipoOperacion) {
    cout << endl << "Ingrese la primera expresion (por ejemplo: 8+2i o 8-2i): ";
    cin >> expresion1;

    if (validarInput(expresion1)) {
        Decodificador(expresion1, numeros1, 0, 1);
        cout << endl << "Ingrese la segunda expresion (por ejemplo: 8+2i o 8-2i): ";
        cin >> expresion2;
        if (validarInput(expresion2)) {
            Decodificador(expresion2, numeros2, 0, 1);
            Numero numero1(numeros1[0], numeros1[1], 'A');
            Numero numero2(numeros2[0], numeros2[1], 'B');
            if (tipoOperacion == 1) {
                numero1 + numero2;
            }
            if (tipoOperacion == 2) {
                numero1 - numero2;
            }
            if (tipoOperacion == 3) {
                numero1 * numero2;
            }
            if (tipoOperacion == 4) {
                numero1 / numero2;
            }
        }
    }
}

int main() {
    int tipoOperacion, numeros1[2], numeros2[2];
    string expresion1, expresion2;

    cout << "NUMEROS COMPLEJOS CON OBJETOS" << endl;
    while (true) {
        cout << endl << "Seleccione una operacion" << endl;
        cout << "1. Suma" << endl << "2. Resta" << endl << "3. Multiplicacion" << endl << "4. Division" << endl << "5. Destructor" << endl << "6. Salir" << endl;
        cin >> tipoOperacion;

        switch (tipoOperacion) {
        case 1:
            cout << endl << "Suma" << endl;
            Input(expresion1, expresion2, numeros1, numeros2, tipoOperacion);
            break;
        case 2:
            cout << endl << "Resta" << endl;
            Input(expresion1, expresion2, numeros1, numeros2, tipoOperacion);
            break;
        case 3:
            cout << endl << "Multiplicacion" << endl;
            Input(expresion1, expresion2, numeros1, numeros2, tipoOperacion);
            break;
        case 4:
            cout << endl << "Division" << endl;
            Input(expresion1, expresion2, numeros1, numeros2, tipoOperacion);
            break;
        case 5:
        {
            Numero numeroA(1, 2, 'A');
            Numero numeroB(3, 4, 'B');
            Numero numeroC(5, 6, 'C');
            Numero numeroD(7, 8, 'D');
            Numero numeroE(9, 10, 'E');

            // Salir del programa
            return 0;
        }
        case 6:
            return 0;
        default:
            cout << "Seleccione una operacion valida" << endl;
            break;
        }
    }
    return 0;
}