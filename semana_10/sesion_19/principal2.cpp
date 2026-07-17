#include <iostream>          
#include <fstream>    
#include <string>       
using namespace std;         

// --- CLASE PACIENTE ---
class Paciente {
private:
    int id;
    string nombre;
    string apellido;
    long long dni;
    string telefono;
public:
    Paciente() : id(0), dni(0) {}
    void setId(int _id) { id = _id; }
    void setNombre(string _nom) { nombre = _nom; }
    void setApellido(string _ape) { apellido = _ape; }
    void setDni(long long _dni) { dni = _dni; }
    void setTelefono(string _tel) { telefono = _tel; }
    void registrar() {
        cout << "\nID: "; cin >> id; cin.ignore();
        cout << "Nombre: "; getline(cin, nombre);
        cout << "Apellido: "; getline(cin, apellido);
        cout << "DNI: "; cin >> dni; cin.ignore();
        cout << "Telefono: "; getline(cin, telefono);
    }
    void mostrar() {
        cout << "ID: " << id << " | " << nombre << " " << apellido << " | DNI: " << dni << " | Tel: " << telefono << "\n";
    }
};

// --- CLASE MEDICO ---
class Medico {
private:
    int id;
    string nombre;
    string apellido;
    string especialidad;
public:
    Medico() : id(0) {}
    void registrar() {
        cout << "\nID: "; cin >> id; cin.ignore();
        cout << "Nombre: "; getline(cin, nombre);
        cout << "Apellido: "; getline(cin, apellido);
        cout << "Especialidad: "; getline(cin, especialidad);
    }
    void mostrar() {
        cout << "ID: " << id << " | Dr./Dra. " << nombre << " " << apellido << " | Especialidad: " << especialidad << "\n";
    }
};

// --- CLASE SERVICIO ---
class Servicio {
private:
    int id;
    string nombre;
    double precio;
public:
    Servicio() : id(0), precio(0.0) {}
    Servicio(int _id, string _nom, double _pre) : id(_id), nombre(_nom), precio(_pre) {}
    void registrar() {
        cout << "\nID: "; cin >> id; cin.ignore();
        cout << "Nombre servicio: "; getline(cin, nombre);
        cout << "Precio: "; cin >> precio; cin.ignore();
    }
    int getId() { return id; }
    string getNombre() { return nombre; }
    void mostrar() {
        cout << "ID: " << id << " | Servicio: " << nombre << " | Precio: S/ " << precio << "\n";
    }
};

// --- CLASE CITA ---
class Cita {
private:
    string nombrePaciente;
    string dniPaciente;
    string nombreMedico;
    string servicio;
    string fecha;
public:
    string getServicio() { return servicio; }
    string getNombrePaciente() { return nombrePaciente; }
    string getDniPaciente() { return dniPaciente; }
    string getNombreMedico() { return nombreMedico; }
    string getFecha() { return fecha; }
    void registrar() {
        cout << "\nNombre paciente: "; getline(cin, nombrePaciente);
        cout << "DNI paciente: "; getline(cin, dniPaciente);
        cout << "Nombre medico: "; getline(cin, nombreMedico);
        cout << "Servicio: "; getline(cin, servicio);
        cout << "Fecha (dd/mm/aaaa): "; getline(cin, fecha);
    }
    void mostrar() {
        cout << "Paciente: " << nombrePaciente << " (" << dniPaciente << ")\n";
        cout << "Medico: " << nombreMedico << " | Servicio: " << servicio << " | Fecha: " << fecha << "\n\n";
    }
};

// --- FUNCIÓN EXPORTAR CITAS ---
void exportarCitasServicio(Cita citas[], int cc, string servicio) {
    ofstream archivo(servicio + ".txt");
    if (!archivo.is_open()) {
        cout << "\nError al crear el archivo.\n";
        return;
    }
    archivo << "====================================\n";
    archivo << "SERVICIO: " << servicio << "\n";               
    archivo << "FECHA DE REPORTE: 12/06/2026\n";               
    archivo << "====================================\n\n";
    int encontradas = 0;                                        
    archivo << "CITAS AGENDADAS:\n";
    archivo << "------------------------------------\n";
    for(int i = 0; i < cc; i++) {
        if (citas[i].getServicio() == servicio) {
            encontradas++;                                      
            archivo << "\nCita #" << encontradas << "\n";
            archivo << "Paciente: " << citas[i].getNombrePaciente() << "\n";
            archivo << "DNI: " << citas[i].getDniPaciente() << "\n";
            archivo << "Medico: " << citas[i].getNombreMedico() << "\n";
            archivo << "Fecha: " << citas[i].getFecha() << "\n";
        }
    }
    if (encontradas == 0) {
        archivo << "No hay citas registradas para este servicio.\n";
    } else {
        archivo << "\n------------------------------------\n";
        archivo << "Total de citas: " << encontradas << "\n";
    }
    archivo.close();
    cout << "\nArchivo '" << servicio << ".txt' creado correctamente con " << encontradas << " cita(s).\n";
}

// --- FUNCIÓN PRINCIPAL ---
int main() {
    Paciente pacientes[20];    
    Medico medicos[20];        
    Servicio servicios[20];    
    Cita citas[20];            

    int cp = 0;  
    int cm = 0;  
    int cs = 0;  
    int cc = 0;  

    // Datos de prueba
    pacientes[0].setId(1);
    pacientes[0].setNombre("Ana");
    pacientes[0].setApellido("García");
    pacientes[0].setDni(40123456);
    pacientes[0].setTelefono("987654321");
    pacientes[1].setId(2);
    pacientes[1].setNombre("Luis");
    pacientes[1].setApellido("Pérez");
    pacientes[1].setDni(41234567);
    pacientes[1].setTelefono("912345678");
    cp = 2;

    servicios[0] = Servicio(1, "Consulta General", 25.0);
    servicios[1] = Servicio(2, "Odontología", 40.0);
    servicios[2] = Servicio(3, "Laboratorio", 35.0);
    cs = 3;

    int opcion;                
    string servicioExportar;    

    do {
        cout << "\n====================================";
        cout << "\n  SISTEMA DE GESTION DE CLINICA";
        cout << "\n====================================";
        cout << "\n1.  Registrar Paciente";
        cout << "\n2.  Registrar Medico";
        cout << "\n3.  Registrar Servicio";
        cout << "\n4.  Registrar Cita";
        cout << "\n5.  Mostrar Pacientes";
        cout << "\n6.  Mostrar Medicos";
        cout << "\n7.  Mostrar Servicios";
        cout << "\n8.  Mostrar Citas";
        cout << "\n9.  Exportar Citas por Servicio";
        cout << "\n10. Salir";
        cout << "\nSeleccione opcion: ";
        cin >> opcion;  

        switch(opcion) {
        case 1:
            if (cp < 20) {
                pacientes[cp].registrar();
                cp++;
                cout << "\nPaciente registrado exitosamente.\n";
            } else cout << "\nCapacidad maxima de pacientes alcanzada.\n";
            break;
        case 2:
            if (cm < 20) {
                medicos[cm].registrar();
                cm++;
                cout << "\nMedico registrado exitosamente.\n";
            } else cout << "\nCapacidad maxima de medicos alcanzada.\n";
            break;
        case 3:
            if (cs < 20) {
                servicios[cs].registrar();
                cs++;
                cout << "\nServicio registrado exitosamente.\n";
            } else cout << "\nCapacidad maxima de servicios alcanzada.\n";
            break;
        case 4:
            if (cc < 20) {
                citas[cc].registrar();
                cc++;
                cout << "\nCita registrada exitosamente.\n";
            } else cout << "\nCapacidad maxima de citas alcanzada.\n";
            break;
        case 5:
            if (cp == 0) cout << "\nNo hay pacientes registrados.\n";
            else { cout << "\n========== LISTADO DE PACIENTES ==========\n"; for(int i=0; i<cp; i++) pacientes[i].mostrar(); }
            break;
        case 6:
            if (cm == 0) cout << "\nNo hay medicos registrados.\n";
            else { cout << "\n========== LISTADO DE MEDICOS ==========\n"; for(int i=0; i<cm; i++) medicos[i].mostrar(); }
            break;
        case 7:
            if (cs == 0) cout << "\nNo hay servicios registrados.\n";
            else { cout << "\n========== LISTADO DE SERVICIOS ==========\n"; for(int i=0; i<cs; i++) servicios[i].mostrar(); }
            break;
        case 8:
            if (cc == 0) cout << "\nNo hay citas registradas.\n";
            else { cout << "\n========== LISTADO DE CITAS ==========\n"; for(int i=0; i<cc; i++) citas[i].mostrar(); }
            break;
        case 9:
            if (cc == 0) cout << "\nNo hay citas registradas.\n";
            else { cin.ignore(); cout << "\nIngrese el nombre del servicio a exportar: "; getline(cin, servicioExportar); exportarCitasServicio(citas, cc, servicioExportar); }
            break;
        case 10:
            cout << "\n====================================";
            cout << "\nGracias por usar el sistema.\n";
            cout << "====================================\n";
            break;
        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n";
        }
    } while(opcion != 10);
    return 0;
}