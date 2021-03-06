#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;
struct Client
{
    string name{""};
    int docs{0};
    int patience{0};
    Client(string name, int docs, int patience) : name(name), docs(docs), patience(patience)
    {
    }
    string str()
    {
        return name + ":" + to_string(docs) + ":" + to_string(patience);
    }
};
std::string fmt(auto data, string open = "[", string close = "]", string sep = ", ")
{
    std::ostringstream ss;
    ss << open;
    for (auto it = data.begin(); it != data.end(); ++it)
        ss << (it != data.begin() ? sep : "") << *it;
    ss << close;
    return ss.str();
}

ostream &operator<<(ostream &os, Client *cli)
{
    return os << cli->str();
}

struct Bank
{
    vector<Client *> tellers; // caixas
    list<Client *> queue_in;  // fila de entrada
    list<Client *> queue_out; // fila de saida
    int docs_gain{0};         // documentos processados
    int docs_lost{0};         // documentos perdidos
    int tics{0};              // quantidade de tempo que passou

    //  Roda o algoritmo de passagem de tempo
    void tic()
    {
        if (!queue_out.empty())
        {
            for (auto it = queue_out.begin(); it != queue_out.end(); it++)
            {
                auto backup = it;
                it = this->queue_out.erase(it);
                delete *backup;
            }
        }

        for (auto &elem : teller)
        {
            if (elem != nullptr)
            {
                if (elem->docs != 0)
                {
                    elem->docs--;
                    this->received++;
                }
                else
                {
                    queue_out.push_back(elem);
                    elem = nullptr;
                }
            }
            else
            {
                if (!queue_in.empty())
                {
                    elem = queue_in.front();
                    queue_in.pop_front();
                }
            }
        }
        auto it = this->queue_in.begin();
        while (it != this->queue_in.end())
        {
            if ((*it)->patience > 0)
            {
                (*it)->patience--;
                ++it;
            }
            else
            {
                auto client = *it;
                queue_out.push_back(client);
                it = queue_in.erase(it);
                this->lost++;
            }
        }
        this->tics++;
    }

    //  iniciliza os caixas com um vetor de nulls
    Bank(int teller_size)
    {
        tellers = vector<Client *>(teller_size, nullptr);
    }

    // deleta qualquer cliente que tenha sobrado no banco
    ~Bank()
    {
        for (auto client : tellers)
            delete client;
        for (auto client : queue_in)
            delete client;
        for (auto client : queue_out)
            delete client;
    }

    //  cria o cliente e insere na fila de entrada
    void arrive(std::string name, int docs, int patience)
    {
        queue_in.push_back(new Client(name, docs, patience));
    }

    //  esta vazio se n??o tem ningu??m no banco
    bool empty()
    {
        if (queue_in.empty())
            return true;

        return false;
    }

    //  Retirar todos os clientes da fila de sa??da
    //
    //  para cada cliente da fila de saida,
    //      this->docs_lost incrementa dos documentos n??o processado
    //      chame o delete para cada um deles
    void empty_queue_out()
    {
        for (auto *client : queue_out)
        {
            this->docs_lost += client->docs;
            delete client;
        }
        queue_out.clear();
    }

    //  Processar caixa
    //
    //  se o caixa tem algum cliente
    //      se o cliente do caixa tiver algum documento para processar
    //          incrementa em um this->docs_gain
    //          decrementa em um os documentos do cliente
    //      sen??o
    //          move o cliente para fila de sa??da
    //  sen??o
    //      se tem alguem na fila de espera
    //          move o primeiro da fila de espera para o caixa
    void process_teller(int index)
    {
        auto &teller = tellers[index];
        if (teller != nullptr)
        {
            if (teller->docs > 0)
            {
                teller->docs -= 1;
                this->docs_gain += 1;
            }
            else
            {
                queue_out.push_back(teller);
                teller = nullptr;
            }
        }
        else if (queue_in.size() > 0)
        {
            teller = queue_in.front();
            queue_in.pop_front();
        }
    }

    //  Processar fila de entrada
    //
    //  para cada cliente da fila de entrada
    //      se a paciencia dele for maior que zero
    //          decremente em um o valor da paciencia
    //      sen??o
    //          mova para fila de saida
    void decrease_patience()
    {
        for (auto it = queue_in.begin(); it != queue_in.end();)
        {
            if ((*it)->patience > 0)
            {
                (*it)->patience -= 1;
                it++;
            }
            else
            {
                queue_out.push_back(*it);
                it = queue_in.erase(it);
            }
        }
    }

    // continua chamando tic at?? todos os clientes terem ido embora
    void finish()
    {
        while (!this->empty())
            tic();
    }

    void show_all()
    {
        for (auto client : teller)
            cout << "[" << (client == nullptr ? "" : client->str()) << "]";

        cout << "entrada: ";
        for (auto client : queue_in)
            cout << client->str() << " ";
        cout << "saida: ";
        for (auto client : queue_out)
            cout << client->str() << " ";
        cout << endl;
    }
};

int main()
{
    Bank banco(3);

    while (true)
    {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        ss >> cmd;
        if (cmd == "end")
        {
            break;
        }
        else if (cmd == "show")
        {
            std::cout << banco.show() << "\n";
        }
        else if (cmd == "in")
        {
            string name{};
            int docs{}, patience{};
            ss >> name >> docs >> patience;
            banco.arrive(name, docs, patience);
        }
        else if (cmd == "init")
        {
            int size{};
            ss >> size;
            banco = Bank(size);
        }
        else if (cmd == "tic")
        {
            banco.tic();
        }
        else if (cmd == "finish")
        {
            banco.finish();
        }
        else
        {
            cout << "fail: command not found\n";
        }
    }
}