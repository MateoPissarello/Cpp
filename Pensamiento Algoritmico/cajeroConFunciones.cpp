#include <iostream>
#include <cstdio>

using namespace std;
long saldo = 15000000;
int opcion = 0;
long valor = 0;
int billetes = 0;
int billeteDeCien = 0;
int billeteDeCincuenta = 0;
int billeteDeVeinte = 0;
int billeteDeDiez = 0;
int calcularVecesQueCabe = 0;
int user = 1234;
int password = 4321;
char decision = ' ';

bool validarUsuario(int usuario, int contrasenia);
void imprimirMenu();
void imprimirSaldo();
long consignar(long valor);
long retirar(long valor);
int contarBilletes(long valor,long denominacion);
void validarOpcion();
void exit();


int main()
{
    int usuario1 = 0;
    int password2 = 0;
    cout << "Por favor ingrese su usuario: ";
    cin >> usuario1;
    cout << "Por favor ingrese su contrasenia: ";
    cin >> password2;
    if(validarUsuario(usuario1, password2)){
        imprimirMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            imprimirSaldo();
            validarOpcion();
            break;
        case 2:
            cout << "\nIngrese el valor a consignar: " << endl;
            cin >> valor;
            cout << "\nSu nuevo saldo es de: " << consignar(valor);
            validarOpcion();
            break;
        case 3:
            cout << "\nIngrese el valor a retirar: " << endl;
            cin >> valor;
            retirar(valor);
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
                validarOpcion();
            break;
        case 4:
            exit();
            break;
        }
    }
    else{
        cout << "Lo sentimos, credenciales invalidos...";
    }
}

void imprimirMenu(){
    cout << "\n\t\tBIENVENIDO AL CAJERO DE @ELMATY\n\n";
    cout << "1. Consultar saldo"  <<endl;
    cout << "2. Consignar"  <<endl;
    cout << "3. Retirar"  <<endl;
    cout << "4. Salir\n" <<endl;
    cout << "Por favor ingrese la opción que desea realizar: " <<endl;
}

void imprimirSaldo(){
    cout << "\nSu saldo es: " <<saldo;
}

long consignar(long valor){
    saldo += valor;
    return saldo;
}
long retirar(long valor){
    int mod = valor % 10000;
    if (valor > saldo || mod != 0 || valor < 0){
     cout << "\nNo puede retirar esa cantidad";
    }
    else{
    if (mod == 0){
        saldo -= valor;
        if (valor >= 100000 && valor / 100000 >= 1){
            billeteDeCien = contarBilletes(valor, 100000);
            valor -= billeteDeCien * 100000;
        }
        if (valor < 100000 && valor / 50000 >= 1){
            billeteDeCincuenta = contarBilletes(valor, 50000);
            valor -= billeteDeCincuenta * 50000;
        }
        if (valor < 50000 && valor / 20000 >= 1){
            billeteDeVeinte = contarBilletes(valor, 20000);
            valor -= billeteDeVeinte * 20000;
        }
        if (valor < 20000 && valor / 10000 >= 1){
            billeteDeDiez = contarBilletes(valor, 10000);
            valor -= billeteDeDiez * 10000;
        }
    }
    }
    return saldo;
    }

int contarBilletes(long valor, long denominacion){
    calcularVecesQueCabe = valor / denominacion;
    return calcularVecesQueCabe;
}

bool validarUsuario(int usuario, int contrasenia){
    bool bandera = false;
    if (usuario == user && contrasenia == password){
        bandera = true;
    } 
    return bandera;
}

void exit(){
    cout << "\nGracias por usar nuestros servicios";
}

void validarOpcion(){
     cout << "\nDesea continuar? (s/n): ";
     cin >> decision;
    if (decision == 's'){
        main();
    }
    else{
        exit();
    }
}