#include <iostream>
#include <fstream> //libreria de flujo de salia a un fichero
#include <stdlib.h>
#include <cstring>
#include <producto.h>


bool comparar(char a[],char b[]); //compara si dos cadenas de caracteres son iguales.
void limpiarpantalla();

using namespace std;

int main()
{
    //saludo de bienvenidad

    cout<<"######                                                           "<<endl;
    cout<<"#     # # ###### #    # #    # ###### #    # # #####   ####      "<<endl;
    cout<<"#     # # #      ##   # #    # #      ##   # # #    # #    #     "<<endl;
    cout<<"######  # #####  # #  # #    # #####  # #  # # #    # #    #     "<<endl;
    cout<<"#     # # #      #  # # #    # #      #  # # # #    # #    #     "<<endl;
    cout<<"#     # # #      #   ##  #  #  #      #   ## # #    # #    #     "<<endl;
    cout<<"######  # ###### #    #   ##   ###### #    # # #####   ####      "<<endl;
    cout << endl;

    ///solicitud de ingreso como usuario o administrador

    string lineainventario;//variable que me guarda el producto
    string lineacantidad;//variable que me guarda la cantidad del producto
    string lineamedida;//variable que me guarda la cantidad del producto

    cout << "Por Favor ingrese su nombre de usuario: ";
    char perfil[15]; //variable para controlar el perfil con el que se ingresa
    cin>>perfil; //atrapar ese perfil

    char admin[6]="admin" ;

    //ciclo que verifica que se ingrese el perfil correcto
//    while(perfil != 1 && perfil != 2)
//    {
//        cout<<"opcion no validad, intente nuevamente: "<<endl;
//        cout<<"opcion: ";
//        cin>>perfil;
//    }


    ///ingreso como usuario

    if(!comparar(perfil,admin))
    {
        cout<<"bienvenido "<<perfil<<endl;
    }

    ///ingreso como administrador

    else
    {
        cout<<"ingrese la clave: ";
        char password[10]="admin2019";
        char c[10];
        cin>>c;
        while(!comparar(c,password))
        {
            cout<<"clave incorrecta"<<endl;
            cout<<"ingrese la clave: ";
            cin>>c;
        }

        ifstream inventario_lectura; //flujo de lectura del inventario
        string inventario; //string para guardar el nombre del producto

        ifstream cantidad_lectura; //flujo de lectura de la cantidad del producto
        ofstream cantidad_escritura;
        string cantidad; //string para guardar la cantidad del producto

        ifstream medida_lectura; //flujo de lectura de la medida del producto
        string medida; //string para guardar la medida del producto

        ofstream cantidadtemporal_escritura;
        ifstream cantidadtemporal_lectura;
        string lineacantidadtemporal;


        limpiarpantalla();
        cout<<"Administrador"<<endl;
        ///leer archivo ID
        inventario_lectura.open("ID.txt"); //abrir o crear un archivo txt.
        if(inventario_lectura.fail()) //condicion que pregunta si no se pudo abrir o se produjo un error
        {
            cout<<"no se puede abrir el archivo"<<endl; //aviso
            exit(1); //salir de todo
        }
        cout<<endl; //salto de linea

        //ciclo para mostrar los nombres y el ID del inventario

        while(!inventario_lectura.eof())
        {
            getline(inventario_lectura,inventario);
            cout<<inventario<<endl;
        }

        // cerrar flujo de lectura del archivo ID
        inventario_lectura.close();

        /// selecionar los productos para modificar

        int ID=0; //inicializo variable ID
        int control=0; //variable que me controla el cerrado de la actualizacion del inventario
        while(control != 404) //ciclo que me corre hasta que el administrador decidad cerrar sesion
        {
            producto producto1; //clase producto
            int contador=0; //contador de lineas en el archivo txt
            cout<<"Ingrese el ID del producto que desea actualizar o 404 para cerrar sesion y guardar cambios."<<endl; //solicitud sobre cual producto va a actualizar
            cout<<"ID: "; //solicitud del ID del producto
            cin>>ID; //atrapar ese ID
            control=ID; //igualar control al ID

            //abrir flujo de lectura del archivo inventario
            inventario_lectura.open("inventario.txt"); //abrir o crear un archivo txt.
            if(inventario_lectura.fail()) //condicion que pregunta si no se pudo abrir o se produjo un error
            {
                cout<<"no se puede abrir el archivo inventario"<<endl; //aviso
                exit(1); //salir de todo
            }

            //abrir flujo de lectura del archivo cantidad
//            cantidad_lectura.open("cantidad.txt"); //abrir o crear un archivo txt.
//            if(cantidad_lectura.fail()) //condicion que pregunta si no se pudo abrir o se produjo un error
//            {
//                cout<<"no se puede abrir el archivo cantidad "<<endl; //aviso
//                exit(1); //salir de todo
//            }

            //abrir flujo de lectura del archivo medida
            medida_lectura.open("medida.txt"); //abrir archivo txt para leer
            if(cantidad_lectura.fail()) //condicion que pregunta si no se pudo abrir o se produjo un error
            {
                cout<<"no se puede abrir el archivo medida "<<endl; //aviso
                exit(1); //salir de todo
            }

            //abrir flujo de ecritura en cantidad temporal
            cantidadtemporal_escritura.open("cantidadtemporal.txt"); //abrir archivo txt para leer
            if(cantidadtemporal_escritura.fail()) //condicion que pregunta si no se pudo abrir o se produjo un error
            {
                cout<<"no se puede abrir el archivo cantidad temporal "<<endl; //aviso
                exit(1); //salir de todo
            }


            //abrir flujo de lectura cantidad
            cantidad_lectura.open("cantidad.txt");
            if(cantidad_lectura.fail()) //condicion que pregunta si no se pudo abrir o se produjo un error
            {
                cout<<"no se puede abrir el archivo cantidad  "<<endl; //aviso
                exit(1); //salir de todo
            }
            ///ciclo para actualizar el inventario
            ///
            double cantidadnueva = 0; //creo string para la cantidad nueva

            while(getline(inventario_lectura, lineainventario)) //ciclo que recorre todo el inventario y atrapa linea por linea
            {
                getline(cantidad_lectura, lineacantidad);  //atrapa la cantidad linea por linea
                getline(medida_lectura,lineamedida); //atrapa la medida linea por linea
                if(contador==ID) //condicion para saber si ya esta en la linea que solicito el administrador
                {
                    producto1.setNombre(lineainventario); //clase producto, agrego el nombre
                    producto1.setCantidad(std::stod(lineacantidad)); //clase produto agrego cantidad
                    producto1.setMedida(lineamedida); //clase producto agrego medida
                    cout<<"Hay "<<producto1.getCantidad()<<" "<<producto1.getMedida()<<" de "<<producto1.getNombre()<<" en el inventario actualmente"<<endl; //informo cantidad actual de x producto
                    cout<<"cuantos "<<producto1.getNombre()<<"desea agregar: "; //solicito que se ingrese la cantidad nueva de x producto
                    cin>>cantidadnueva; //tomo el string
                    producto1.setCantidad(producto1.getCantidad()+cantidadnueva);
                    //string prueba="12345";
                    cantidadtemporal_escritura<<std::to_string(producto1.getCantidad()); //guardo la cantidad nueva en el archivo temporal
                    cantidadtemporal_escritura<<'\n'; //agrego salto de linea
                }
                if(contador!=ID) //condicion que pregunta si el ID es diferente del contador (esto para no repetir agregar el valor nuevo, si no para sobreescribirlo)
                {
                    cantidadtemporal_escritura<<lineacantidad; //tomo la linea y la escribo en el archivo tal cual
                    cantidadtemporal_escritura<<'\n'; //agrego salto de linea
                }
                contador++; //sumo al contador
            }
            cantidad_lectura.close(); //cierro flujo de lectura de cantidad
            inventario_lectura.close(); //cierro flujo de lectura de inventario
            medida_lectura.close(); //cierro flujo de lectura de medida
            cantidadtemporal_escritura.close(); //cierro flujo de escritura de cantdad temporal

            ///actualizacion del archvo cantidad

            cantidad_escritura.open("cantidad.txt"); //abro flujo de escritura del archivo cantidad
            if(cantidad_escritura.fail()) //condicion que pregunta si no se pudo abrir o se produjo un error
            {
                cout<<"no se puede abrir el archivo cantidad  "<<endl; //aviso
                exit(1); //salir de todo
            }
            cantidadtemporal_lectura.open("cantidadtemporal.txt"); //abro flujo de lectura del archivo cantidadtemporal
            if(cantidadtemporal_lectura.fail()) //condicion que pregunta si no se pudo abrir o se produjo un error
            {
                cout<<"no se puede abrir el archivo cantidad  "<<endl; //aviso
                exit(1); //salir de todo
            }
            while(getline(cantidadtemporal_lectura, lineacantidadtemporal)) //ciclo que me lee todo el archivo linea por linea
            {
                cantidad_escritura<<lineacantidadtemporal; //agrego cada linea al archivo cantidad
                cantidad_escritura<<'\n'; //agrego salto de linea
            }
            cout<<"actualizacion..."<<endl;
            cout<<"Hay "<<producto1.getCantidad()<<" "<<producto1.getMedida()<<" de "<<producto1.getNombre()<<" en el inventario actualmente"<<endl; //informo cantidad actual de x producto
            cantidad_escritura.close(); //cierro flujo de escritura del archivo cantidad
            cantidadtemporal_lectura.close(); //cierro flujo de lectura del archivo cantidadtemporal

        }

        cout<<"sesion cerrada"<<endl;
    }



    int op=0;
    while(op==0)
    {



    }
}


bool comparar(char a[],char b[])
{
    if(strlen(a)!=strlen(b))
    {
        return false;
    }
    else
    {
        int i=0;
        while(a[i]!='\0')
        {
            if(a[i]!=b[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }

}

void limpiarpantalla()
{
    system("cls");
}
