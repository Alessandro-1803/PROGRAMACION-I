#include <iostream>
#include <string>
using namespace std;

// CLASE BASE: CUENTA BANCARIA
class Cuenta {
protected:
    string numeroCuenta;
    string titular;
    double saldo;

public:
    // Constructor parametrizado
    Cuenta(string _num, string _tit, double _sal) {
        numeroCuenta = _num;
        titular = _tit;
        saldo = _sal;
    }

    // Métodos virtuales para redefinir en clases hijas
    virtual void mostrarDatos() = 0; // Método abstracto
    virtual void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "✅ Depósito de S/ " << monto << " realizado.\n";
        } else {
            cout << "❌ Monto inválido.\n";
        }
    }

    virtual void retirar(double monto) = 0; // Método abstracto

    // Getter para saldo
    double getSaldo() { return saldo; }
};

// CLASE DERIVADA: CAJA DE AHORROS
class CajaAhorros : public Cuenta {
private:
    double tasaInteres; // Porcentaje anual
public:
    CajaAhorros(string _num, string _tit, double _sal, double _tasa)
        : Cuenta(_num, _tit, _sal) {
        tasaInteres = _tasa;
    }

    // Implementar método mostrarDatos
    void mostrarDatos() override {
        cout << "\n=====================================\n";
        cout << "          CAJA DE AHORROS            \n";
        cout << "Número de cuenta: " << numeroCuenta << "\n";
        cout << "Titular: " << titular << "\n";
        cout << "Saldo actual: S/ " << saldo << "\n";
        cout << "Tasa de interés anual: " << tasaInteres << "%\n";
        cout << "=====================================\n";
    }

    // Implementar método retirar (sin comisiones)
    void retirar(double monto) override {
        if (monto <= 0) {
            cout << "❌ Monto inválido.\n";
            return;
        }
        if (monto > saldo) {
            cout << "❌ Saldo insuficiente.\n";
            return;
        }
        saldo -= monto;
        cout << "✅ Retiro de S/ " << monto << " realizado.\n";
        cout << "Saldo restante: S/ " << saldo << "\n";
    }

    // Calcular interés mensual
    void calcularInteres() {
        double interes = saldo * (tasaInteres / 100) / 12;
        saldo += interes;
        cout << "✅ Interés mensual agregado: S/ " << interes << "\n";
        cout << "Nuevo saldo: S/ " << saldo << "\n";
    }
};

// CLASE DERIVADA: CUENTA CORRIENTE
class CuentaCorriente : public Cuenta {
private:
    double limiteSobregiro; // Monto máximo permitido en negativo
    double comisionRetiro;  // Porcentaje por cada retiro
public:
    CuentaCorriente(string _num, string _tit, double _sal, double _limite, double _comision)
        : Cuenta(_num, _tit, _sal) {
        limiteSobregiro = _limite;
        comisionRetiro = _comision;
    }

    // Implementar método mostrarDatos
    void mostrarDatos() override {
        cout << "\n=====================================\n";
        cout << "         CUENTA CORRIENTE            \n";
        cout << "Número de cuenta: " << numeroCuenta << "\n";
        cout << "Titular: " << titular << "\n";
        cout << "Saldo actual: S/ " << saldo << "\n";
        cout << "Límite de sobregiro: S/ " << limiteSobregiro << "\n";
        cout << "Comisión por retiro: " << comisionRetiro << "%\n";
        cout << "=====================================\n";
    }

    // Implementar método retirar (con comisión y sobregiro)
    void retirar(double monto) override {
        if (monto <= 0) {
            cout << "❌ Monto inválido.\n";
            return;
        }
        double totalCobrar = monto + (monto * comisionRetiro / 100);
        if (totalCobrar > saldo + limiteSobregiro) {
            cout << "❌ Excede el límite de sobregiro permitido.\n";
            return;
        }
        saldo -= totalCobrar;
        cout << "✅ Retiro de S/ " << monto << " realizado.\n";
        cout << "Comisión aplicada: S/ " << (monto * comisionRetiro / 100) << "\n";
        cout << "Saldo actual: S/ " << saldo << "\n";
    }
};

// FUNCIÓN PRINCIPAL DE PRUEBA
int main() {
    // Crear cuentas de prueba
    CajaAhorros ahorros("001-12345", "Ana García", 1500.0, 5.2);
    CuentaCorriente corriente("002-67890", "Luis Pérez", 800.0, 1000.0, 2.5);

    // Probar Caja de Ahorros
    ahorros.mostrarDatos();
    ahorros.depositar(500.0);
    ahorros.retirar(300.0);
    ahorros.calcularInteres();

    // Probar Cuenta Corriente
    corriente.mostrarDatos();
    corriente.depositar(200.0);
    corriente.retirar(900.0); // Usa sobregiro
    corriente.retirar(1500.0); // Excede límite

    return 0;
}