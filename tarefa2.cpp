#include <iostream>
#include <string>

using namespace std;

struct Node {
    string word;
    Node* next;
    Node* prev;

    Node(string w) : word(w), next(nullptr), prev(nullptr) {}
};

class Editor {
private:
    Node* head;
    int size;

public:
    Editor() : head(nullptr), size(0) {}

    ~Editor() {
        while (size > 0) {
            removeWord(0);
        }
    }

    void display() {
        if (!head) {
            cout << "[frase vazia]" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < size; i++) {
            cout << temp->word;
            if (i < size - 1) cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayReverse() {
        if (!head) {
            cout << "[frase vazia]" << endl;
            return;
        }

        Node* temp = head->prev;
        for (int i = 0; i < size; i++) {
            cout << temp->word;
            if (i < size - 1) cout << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void insertWord(string word, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Posição inválida!" << endl;
            return;
        }

        Node* newNode = new Node(word);

        if (size == 0) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* curr = head;
            for (int i = 0; i < pos; i++) {
                curr = curr->next;
            }

            Node* prevNode = curr->prev;

            prevNode->next = newNode;
            newNode->prev = prevNode;

            newNode->next = curr;
            curr->prev = newNode;

            if (pos == 0)
                head = newNode;
        }
        size++;
    }

    void correctWord(int pos, string newWord) {
        if (pos < 0 || pos >= size) {
            cout << "Posição inválida!" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }

        temp->word = newWord;
    }

    void removeWord(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Posição inválida!" << endl;
            return;
        }

        Node* curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }

        if (size == 1) {
            delete curr;
            head = nullptr;
        } else {
            Node* prevNode = curr->prev;
            Node* nextNode = curr->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            if (curr == head)
                head = nextNode;

            delete curr;
        }

        size--;
    }

    int getSize() {
        return size;
    }
};

// Menu simples para usar o editor
int main() {
    Editor editor;
    int opcao;
    string palavra;
    int pos;

    do {
        cout << "\n--- Editor de Frase ---" << endl;
        editor.display();
        cout << "[1] Inserir palavra\n[2] Corrigir palavra\n[3] Remover palavra\n[4] Mostrar reverso\n[0] Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Palavra a inserir: ";
            cin >> palavra;
            cout << "Posição (0 a " << editor.getSize() << "): ";
            cin >> pos;
            editor.insertWord(palavra, pos);
            break;
        case 2:
            cout << "Posição da palavra a corrigir (0 a " << editor.getSize() - 1 << "): ";
            cin >> pos;
            cout << "Nova palavra: ";
            cin >> palavra;
            editor.correctWord(pos, palavra);
            break;
        case 3:
            cout << "Posição da palavra a remover (0 a " << editor.getSize() - 1 << "): ";
            cin >> pos;
            editor.removeWord(pos);
            break;
        case 4:
            cout << "Frase ao contrário:\n";
            editor.displayReverse();
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}
