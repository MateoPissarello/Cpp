#include <iostream>
#include <cstdio>

using namespace std;

long saldo = 15000000;
int opcion = 0;
long valor = 0;
int billetes = 0;
long saldoviejo = 0;
int billeteDeCien = 0;
int billeteDeCincuenta = 0;
int billeteDeVeinte = 0;
int billeteDeDiez = 0;
int calcularVecesQueCabe = 0;
bool salir = false;

int main()
{
    while (!salir)
    {
        /* code */
        cout << "\n\t\tBIENVENIDO AL CAJERO DE @ELMATY\n\n";
        cout << "1. Consultar saldo"  <<endl;
        cout << "2. Consignar"  <<endl;
        cout << "3. Retirar"  <<endl;
        cout << "4. Salir\n" <<endl;
        cout << "Por favor ingrese la opción que desea realizar" <<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "\nSu saldo es: " <<saldo;
            break;
        case 2:
            cout << "\nIngrese el valor a consignar: " << endl;
            cin >> valor;
            saldo += valor;
            cout << "\nSu nuevo saldo es de: " <<saldo <<endl;
            break;
        case 3:
            cout << "\nIngrese el valor a retirar: " << endl;
            cin >> valor;
            if (valor > saldo || valor % 10000 != 0)
            {
                cout << "\nNo puede retirar esa cantidad";
            }
            else{
                if (valor % 10000 == 0){
                    saldoviejo = saldo;
                    saldo -= valor;
                }
                if (valor >= 100000 && valor / 100000 >= 1)
                {
                    calcularVecesQueCabe = valor / 100000;
                    valor -= (calcularVecesQueCabe * 100000);
                    billeteDeCien = calcularVecesQueCabe;
                }
                if (valor < 100000 && valor / 50000 >= 1 )
                {
                    calcularVecesQueCabe = valor / 50000;
                    valor -= (calcularVecesQueCabe * 50000);
                    billeteDeCincuenta = calcularVecesQueCabe;
                }
                if (valor < 50000 && valor / 20000 >= 1)
                {
                    calcularVecesQueCabe = valor / 20000;
                    valor -= (calcularVecesQueCabe * 20000);
                    billeteDeVeinte = calcularVecesQueCabe;
                }
                if (valor < 20000 && valor / 10000 >=1)
                {
                    calcularVecesQueCabe = valor / 10000;
                    valor -= (calcularVecesQueCabe * 10000);
                    billeteDeDiez = calcularVecesQueCabe;
                }
                cout << "\nRetirando" << endl;
                if (billeteDeCien > 0)
                {
                    printf("Le entrego %d billetes de 100000\n",billeteDeCien);
                }
                if (billeteDeCincuenta > 0)
                {
                    printf("Le entrego %d billetes de 50000\n",billeteDeCincuenta);
                }
                if (billeteDeVeinte > 0)
                {
                    printf("Le entrego %d billetes de 20000\n",billeteDeVeinte);
                }
                
                if (billeteDeDiez > 0)
                {
                    printf("Le entrego %d billetes de 10000\n",billeteDeDiez);
                }
            }
            break;
        case 4:
            cout << "\nGracias por utilizar nuestros servicios";
            salir = true;
            break;
        default:
        cout << "\nUsted ha ingresado una opción inválido";
            break;
    }
    } 
}
