#include <iostream>
#include <string>

using namespace std;

// Sistema de registro e gestão de contas bancárias (Etapa 1).
// Usa apenas variáveis individuais, sem arrays, por isso só é
// possível ter uma conta cadastrada por vez (cadastrar de novo
// sobrescreve a conta anterior).

int main() {

    int opcao;
    int numeroConta;
    string nomeCliente;
    string cpf;
    int tipoConta;
    double saldo;
    bool contaAtiva;
    bool contaCadastrada = false; // começa falso: nenhuma conta existe ainda no sistema

    // Loop principal do menu: repete o bloco até opcao ser 6 (Sair),
    // fazendo o menu reaparecer após cada operação escolhida.
    do {
        cout << "==============================" << endl;
        cout << "        Banco Beiramar         " << endl;
        cout << "==============================" << endl;
        cout << "1 - Cadastrar conta"        << endl;
        cout << "2 - Consultar conta"        << endl;
        cout << "3 - Verificar saldo"        << endl;
        cout << "4 - Alterar tipo da conta"  << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair"                   << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        // Direciona para o bloco certo de acordo com a opção digitada.
        switch (opcao) {

            case 1: // Cadastrar uma nova conta.
                cout << "===========CADASTRO===========" << endl;

                cout << "Digite o seu nome: " << endl;
                // Limpa o \n que sobrou do "cin >> opcao" acima, senão
                // o getline abaixo leria essa quebra de linha e pularia o nome.
                cin.ignore();
                getline(cin, nomeCliente); // lê a linha toda, aceita nomes com espaço

                cout << "Digite o seu CPF: " << endl;
                cin >> cpf;
                // Repete a pergunta enquanto o CPF não tiver exatamente 11 dígitos.
                while (cpf.length() != 11) {
                    cout << "CPF invalido!" << endl;
                    cin >> cpf;
                }

                cout << "Qual o tipo de conta? (1-Corrente, 2-Poupanca): " << endl;
                cin >> tipoConta;
                // Só aceita 1 ou 2; qualquer outro valor faz o while repetir.
                while (tipoConta != 1 && tipoConta != 2) {
                    cout << "Opção invalida!" << endl;
                    cin >> tipoConta;
                }

                cout << "Quanto voce quer depositar? " << endl;
                cin >> saldo;
                // Bloqueia valores negativos; zero é permitido como saldo inicial.
                while (saldo < 0) {
                    cout << "Saldo invalido!" << endl;
                    cin >> saldo;
                }

                cout << "Digite o numero da sua conta: " << endl;
                cin >> numeroConta;
                // O número da conta precisa ser maior que ze.
                while (numeroConta <= 0) {
                    cout << "Número invalido!" << endl;
                    cin >> numeroConta;
                }

                contaAtiva = true;       // toda conta nova começa ativa
                contaCadastrada = true;  // libera o uso dos outros cases (2 a 5)

                cout << "==============================" << endl;
                cout << "     CADASTRO FINALIZADO       " << endl;
                cout << "==============================" << endl;
                cout << "Nome: "            << nomeCliente << endl;
                cout << "CPF: "             << cpf         << endl;
                cout << "Numero da conta: " << numeroConta << endl;
                cout << "Tipo da conta: "   << tipoConta   << endl;
                cout << "Saldo atual: "     << saldo       << endl;
                break;

            case 2: // Consultar os dados da conta já cadastrada.
                if (contaCadastrada == false) {
                    // Impede exibir variáveis vazias/lixo se ninguém cadastrou ainda.
                    cout << "Nenhuma conta cadastrada ainda!" << endl;
                }
                else {
                    cout << "===========DADOS DA CONTA===========" << endl;
                    cout << "Nome: "            << nomeCliente << endl;
                    cout << "CPF: "             << cpf         << endl;
                    cout << "Numero da conta: " << numeroConta << endl;

                    // Traduz o número guardado (1 ou 2) para o nome do tipo.
                    if (tipoConta == 1) {
                        cout << "Tipo da conta: Corrente" << endl;
                    }
                    else {
                        cout << "Tipo da conta: Poupanca" << endl;
                    }

                    if (contaAtiva == true) {
                        cout << "Situação: Ativa" << endl;
                    }
                    else {
                        cout << "Situação: Desativada" << endl;
                    }
                }
                break;

            case 3: // Verificar apenas o saldo (sem mostrar os outros dados).
                if (contaCadastrada == false) {
                    cout << "Nenhuma conta cadastrada ainda!" << endl;
                }
                else if (contaAtiva == false) {
                    // Regra do enunciado: operações assim dependem de contaAtiva.
                    cout << "Conta desativada. Nao e possivel verificar o saldo." << endl;
                }
                else {
                    cout << "Saldo atual: " << saldo << endl;
                }
                break;

            case 4: // Trocar o tipo da conta (Corrente/Poupanca).
                if (contaCadastrada == false) {
                    cout << "Nenhuma conta cadastrada ainda!" << endl;
                }
                else if (contaAtiva == false) {
                    cout << "Conta desativada. Nao e possivel alterar o tipo." << endl;
                }
                else {
                    cout << "Novo tipo? (1-Corrente, 2-Poupanca): " << endl;
                    cin >> tipoConta;
                    // Mesma validação usada no cadastro, para não aceitar valor inválido aqui também.
                    while (tipoConta != 1 && tipoConta != 2) {
                        cout << "Opção invalida!" << endl;
                        cin >> tipoConta;
                    }
                    cout << "Tipo da conta atualizado!" << endl;
                }
                break;

            case 5: // Alternar a conta entre ativa e desativada.
                if (contaCadastrada == false) {
                    cout << "Nenhuma conta cadastrada ainda!" << endl;
                }
                else if (contaAtiva == true) {
                    // Estava ativa: desativa.
                    contaAtiva = false;
                    cout << "Conta desativada." << endl;
                }
                else {
                    // Estava desativada: ativa de novo.
                    contaAtiva = true;
                    cout << "Conta ativada." << endl;
                }
                break;

            case 6: // Encerra o programa (condição de parada do do-while).
                cout << "Saindo..." << endl;
                break;

            default: // Cai aqui se o número digitado não for nenhuma opção do menu.
                cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 6);

    return 0;
}
