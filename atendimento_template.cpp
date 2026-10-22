#include <iostream>
#include <string>
using namespace std;

struct No {
    string nome;
    int    urgencia;
    No*    prox;
    No(const string& n, int u = 0) : nome(n), urgencia(u), prox(nullptr) {}
};

struct FilaPacientes {
    No* frente = nullptr;
    No* tras   = nullptr;

    void enqueue(const string& nome, int urgencia) {
        No* novo = new No(nome, urgencia);

        if (isEmpty()) {
            frente = novo;
            tras = novo;
        } else {
            tras->prox = novo;
            tras = novo;
        }
    }

    string dequeue() {
        if (isEmpty()) return "";

        No* removido = frente;
        string nome = removido->nome;
        frente = frente->prox;

        if (frente == nullptr) {
            tras = nullptr;
        }

        delete removido;
        return nome;
    }

    string frente_peek() const {
        if (isEmpty()) return "";
        return frente->nome;
    }

    bool isEmpty() const { return frente == nullptr; }

    int tamanho() const {
        int cont = 0;
        No* p = frente;

        while (p) {
            cont++;
            p = p->prox;
        }

        return cont;
    }

    ~FilaPacientes() {
        while (!isEmpty()) dequeue();
    }
};

struct PilhaHistorico {
    No* topo = nullptr;

    void push(const string& nome) {
        No* novo = new No(nome);
        novo->prox = topo;
        topo = novo;
    }

    string pop() {
        if (isEmpty()) return "";

        No* removido = topo;
        string nome = removido->nome;
        topo = topo->prox;

        delete removido;
        return nome;
    }

    string peek() const {
        if (isEmpty()) return "";
        return topo->nome;
    }

    bool isEmpty() const { return topo == nullptr; }

    ~PilhaHistorico() {
        while (!isEmpty()) pop();
    }
};

struct ListaMedicos {
    No* head = nullptr;

    void adicionarMedico(const string& nome) {
        No* novo = new No(nome);

        if (!head) {
            head = novo;
            return;
        }

        No* p = head;
        while (p->prox) {
            p = p->prox;
        }

        p->prox = novo;
    }

    string chamarMedico() {
        if (!head) return "";

        No* removido = head;
        string nome = removido->nome;
        head = head->prox;

        delete removido;
        return nome;
    }

    void percorrer(const string& prefixo = "") const {
        if (!prefixo.empty()) cout << prefixo << ": ";

        cout << "(lista vazia)\n";
    }

    bool temMedico() const { return head != nullptr; }

    ~ListaMedicos() {
        while (head) {
            No* t = head;
            head  = head->prox;
            delete t;
        }
    }
};

void imprimirHistorico(PilhaHistorico& hist) {
    cout << "\n=== Relatório de Atendimentos ===\n";
    if (hist.isEmpty()) {
        cout << "(nenhum atendimento registrado)\n";
        return;
    }

}
