#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

class Paciente {
public:
    string cpf;
    string nome;
    string dataNascimento;

    Paciente(const string& cpf, const string& nome, const string& dataNascimento) 
        : cpf(cpf), nome(nome), dataNascimento(dataNascimento) {}
};

class Medico {
public:
    string crm;
    string nome;
    string especialidade;

    Medico(const string& crm, const string& nome, const string& especialidade)
        : crm(crm), nome(nome), especialidade(especialidade) {}
};

vector<Paciente> pacientes;
vector<Medico> medicos;
// Função para validar o formato da data (XX/XX/XXXX)
bool isDateValid(const string& date) {
    regex datePattern(R"(\d{2}/\d{2}/\d{4})");
    return regex_match(date, datePattern);
}

// Função para validar o formato do CPF (11 dígitos)
bool isCpfValid(const string& cpf) {
    regex cpfPattern(R"(\d{11})");
    return regex_match(cpf, cpfPattern);
}
// Função para validar o formato do CRM (6 dígitos)
bool isCrmValid(const string& crm) {
    regex cpfPattern(R"(\d{6})");
    return regex_match(crm, cpfPattern);
}

void incluirPaciente() {
    string cpf, nome, dataNascimento;
    cout << "CPF (11 digitos): ";
    cin >> cpf;
    if(!isCpfValid(cpf)){
        cout << "CPF invalido" << endl;
        return;
    }
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Data de Nascimento (dd/mm/aaaa): ";
    getline(cin, dataNascimento);
    if(!isDateValid(dataNascimento)){
        cout << "Data invalida" << endl;
        return;
    }
    Paciente novoPaciente(cpf, nome, dataNascimento);
    pacientes.push_back(novoPaciente);
    cout << "Paciente incluido com sucesso!" << endl;
}

void excluirPaciente() {
    string cpf;
    cout << "Informe o CPF do paciente a ser excluido: ";
    cin >> cpf;
    for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
        if (it->cpf == cpf) {
            pacientes.erase(it);
            cout << "Paciente excluido com sucesso!" << endl;
            return;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

void alterarPaciente() {
    string cpf;
    cout << "Informe o CPF do paciente a ser alterado: ";
    cin >> cpf;
    for (auto &paciente : pacientes) {
        if (paciente.cpf == cpf) {
            cout << "Dados atuais do paciente:" << endl;
            cout << "Nome: " << paciente.nome << endl;
            cout << "Data de Nascimento: " << paciente.dataNascimento << endl;

            string opcao;
            cout << "Deseja alterar o nome? (S/N): ";
            cin >> opcao;
            if (opcao == "S" || opcao == "s") {
                cout << "Novo nome: ";
                cin.ignore();
                getline(cin, paciente.nome);
            }

            cout << "Deseja alterar a data de nascimento? (S/N): ";
            cin >> opcao;
            if (opcao == "S" || opcao == "s") {
                cout << "Nova data de Nascimento: ";
                cin.ignore();
                getline(cin, paciente.dataNascimento);
            }

            cout << "Dados do paciente alterados com sucesso!" << endl;
            return;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

void listarPacientes() {
    cout << "Lista de Pacientes:" << endl;
    for (const Paciente &paciente : pacientes) {
        cout << "CPF: " << paciente.cpf << " - Nome: " << paciente.nome << " - Data de Nascimento: " << paciente.dataNascimento << endl;
    }
}

void localizarPaciente() {
    string cpf;
    cout << "Informe o CPF do paciente a ser localizado: ";
    cin >> cpf;
    for (const Paciente &paciente : pacientes) {
        if (paciente.cpf == cpf) {
            cout << "Paciente encontrado:" << endl;
            cout << "CPF: " << paciente.cpf << " - Nome: " << paciente.nome << " - Data de Nascimento: " << paciente.dataNascimento << endl;
            return;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

void incluirMedico() {
    string crm, nome, especialidade;
    cout << "CRM (6 digitos): ";
    cin >> crm;
    if(!isCrmValid(crm)){
        cout << "CRM invalido" << endl;
        return;
    }
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Especialidade: ";
    getline(cin, especialidade);
    Medico novoMedico(crm, nome, especialidade);
    medicos.push_back(novoMedico);

    cout << "Médico incluido com sucesso!" << endl;
}

void excluirMedico() {
    string crm;
    cout << "Informe o CRM do medico a ser excluido: ";
    cin >> crm;
    for (auto it = medicos.begin(); it != medicos.end(); ++it) {
        if (it->crm == crm) {
            medicos.erase(it);
            cout << "Medico excluido com sucesso!" << endl;
            return;
        }
    }
    cout << "Medico nao encontrado." << endl;
}

void alterarMedico() {
    string crm;
    cout << "Informe o CRM do medico a ser alterado: ";
    cin >> crm;
    for (auto &medico : medicos) {
        if (medico.crm == crm) {
            cout << "Dados atuais do medico:" << endl;
            cout << "Nome: " << medico.nome << endl;
            cout << "Especialidade: " << medico.especialidade << endl;

            string opcao;
            cout << "Deseja alterar o nome? (S/N): ";
            cin >> opcao;
            if (opcao == "S" || opcao == "s") {
                cout << "Novo nome: ";
                cin.ignore();
                getline(cin, medico.nome);
            }

            cout << "Deseja alterar a especialidade? (S/N): ";
            cin >> opcao;
            if (opcao == "S" || opcao == "s") {
                cout << "Nova especialidade: ";
                cin.ignore();
                getline(cin, medico.especialidade);
            }

            cout << "Dados do médico alterados com sucesso!" << endl;
            return;
        }
    }
    cout << "Médico não encontrado." << endl;
}

void listarMedicos() {
    cout << "Lista de Médicos:" << endl;
    for (const Medico &medico : medicos) {
        cout << "CRM: " << medico.crm << " - Nome: " << medico.nome << " - Especialidade: " << medico.especialidade << endl;
    }
}

void localizarMedico() {
    string crm;
    cout << "Informe o CRM do médico a ser localizado: ";
    cin >> crm;
    for (const Medico &medico : medicos) {
        if (medico.crm == crm) {
            cout << "Médico encontrado:" << endl;
            cout << "CRM: " << medico.crm << " - Nome: " << medico.nome << " - Especialidade: " << medico.especialidade << endl;
            return;
        }
    }
    cout << "Médico não encontrado." << endl;
}
class Data {
    int dia, mes, ano;

public:
    Data(int _dia, int _mes, int _ano) {
        this->setData(_dia, _mes, _ano);
    }

    void setDia(int _dia) {
        if (dataValida(_dia, this->mes, this->ano)) {
            this->dia = _dia;
        }
    }

    int getDia() {
        return this->dia;
    }

    void setMes(int _mes) {
        if (dataValida(this->dia, _mes, this->ano)) {
            this->mes = _mes;
        }
    }

    int getMes() {
        return this->mes;
    }

    void setAno(int _ano) {
        if (dataValida(this->dia, this->mes, _ano)) {
            this->ano = _ano;
        }
    }

    int getAno() {
        return this->ano;
    }

    void setData(int _dia, int _mes, int _ano) {
        if (!dataValida(_dia, _mes, _ano)) {
            return;
        }

        this->dia = _dia;
        this->mes = _mes;
        this->ano = _ano;
    }

    string toString() {
        stringstream ss;
        ss << this->dia << "/" << this->mes << "/" << this->ano;
        return ss.str();
    }

    static bool dataValida(int _dia, int _mes, int _ano) {
        int maxDias = 31;

        if ((_mes < 1 || _mes > 12) || (_ano < 1900)) {
            cout << "Data inválida!" << endl;
            return false;
        }

        if (_mes == 2) {
            maxDias = 28;
            if (_ano % 4 == 0) {
                maxDias = 29;
            }
        }

        if (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11) {
            maxDias = 30;
        }

        if (_dia < 1 || _dia > maxDias) {
            cout << "Data inválida!" << endl;
            return false;
        }

        return true;
    }

    static bool dataValida(Data* _data) {
        return dataValida(_data->getDia(), _data->getMes(), _data->getAno());
    }
};

int main() {
    int opcao;

    do {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Gestao de Pacientes" << endl;
        cout << "2. Gestao de Medicos" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                int opcaoPaciente;
                do {
                    cout << "MENU DE GESTAO DE PACIENTES" << endl;
                    cout << "1. Incluir Paciente" << endl;
                    cout << "2. Excluir Paciente" << endl;
                    cout << "3. Alterar Paciente" << endl;
                    cout << "4. Listar Pacientes" << endl;
                    cout << "5. Localizar Paciente" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> opcaoPaciente;

                    switch (opcaoPaciente) {
                        case 1:
                            incluirPaciente();
                            break;
                        case 2:
                            excluirPaciente();
                            break;
                        case 3:
                            alterarPaciente();
                            break;
                        case 4:
                            listarPacientes();
                            break;
                        case 5:
                            localizarPaciente();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcao invalida." << endl;
                    }
                } while (opcaoPaciente != 0);
                break;

            case 2:
                int opcaoMedico;
                do {
                    cout << "MENU DE GESTAO DE MEDICOS" << endl;
                    cout << "1. Incluir Medico" << endl;
                    cout << "2. Excluir Medico" << endl;
                    cout << "3. Alterar Medico" << endl;
                    cout << "4. Listar Medicos" << endl;
                    cout << "5. Localizar Medico" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> opcaoMedico;

                    switch (opcaoMedico) {
                        case 1:
                            incluirMedico();
                            break;
                        case 2:
                            excluirMedico();
                            break;
                        case 3:
                            alterarMedico();
                            break;
                        case 4:
                            listarMedicos();
                            break;
                        case 5:
                            localizarMedico();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcao invalida." << endl;
                    }
                } while (opcaoMedico != 0);
                break;

            case 0:
                cout << "Encerrando o programa." << endl;
                break;

            default:
                cout << "Opção invalida." << endl;
        }
    } while (opcao != 0);

    return 0;
}
