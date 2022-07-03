#include <iostream>
#include <sstream>
using namespace std;

// double free corruption

struct Vector
{
    int capacity{0};
    int size{0};
    int *data{nullptr};

    Vector(int capacity)
    {
        this->data = new int[capacity];
    }

    void operator=(const Vector &other)
    {
        this->capacity = other.capacity;
        this->size = other.size;
        if (this->data != nullptr)
            delete[] this->data;

        this->data = new int[other.capacity];
        for (int i = 0; i < other.capacity; i++)
            this->data[i] = other.data[i];
    }

    Vector(Vector &other)
    {
        *this = other;
    }
    ~Vector()
    {
        delete[] this->data;
    }
    void add(int value)
    {
        if (this->size < this->capacity)
        {
            this->data[this->size] = value;
            size += 1;
        }
    }

    friend ostream &operator<<(ostream &os, Vector vector)
    {
        os << "[ ";
        for (int i = 0; i < vector.size; i++)
            os << vector.data[i] << " ";
        os << "]";
        return os;
    }
};

/* NAO MEXA DAQUI PRA BAIXO */
int main()
{
    string line, cmd;
    int value;
    Vector v(0);
    while (true)
    {
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if (cmd == "end")
        {
            break;
        }
        else if (cmd == "init")
        {
            ss >> value;
            v = Vector(value);
        }
        else if (cmd == "status")
        {
            cout << "size:" << v.size << " capacity:" << v.capacity << "\n";
        }
        else if (cmd == "add")
        {
            while (ss >> value)
                v.add(value);
        }
        else if (cmd == "show")
        {
            cout << v << endl;
        }
        else
        {
            cout << "fail: comando invalido\n";
        }
    }
}