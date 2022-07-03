#include <iostream>
#include <algorithm>
#include <list>

std::list<char> create_text()
{
    std::string line{};
    std::getline(std::cin, line);
    std::list<char> texto{};

    int count = 0;

    for (auto it = line.begin(); it != line.end(); it++)
    {
        if (count == 0)
        {
            if (*it == '<' || *it == '>' || *it == 'B' || *it == 'D')
            {
                texto.push_back('|');
                count++;
            }
        }

        texto.push_back((*it));

        if (it + 1 == line.end())
        {
            if (count == 0)
                texto.push_back('|');

            texto.push_back('\n');
            break;
        }
    }
    return texto;
}

void Imprimir(std::list<char> &texto)
{
    for (auto &elemento : texto)
        std::cout << elemento;
}

void edita_texto(std::list<char> &texto)
{
    auto cursor = texto.begin();
    int count = 0;

    std::list<char> caracteres{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'w', 'z', '-'};

    for (auto it = texto.begin(); it != texto.end(); it++)
    {
        for (auto it = texto.begin(); it != texto.end(); it++)
        {
            if (*it == '|')
                cursor = it;
        }

        if (*it == 'R')
            *it = '\n';

        if (*it == 'B')
        {
            if (*cursor != texto.front())
            {
                cursor = texto.erase(--cursor);
                it = texto.erase(it);
                --it;
            }
            else
            {
                it = texto.erase(it);
                --it;
            }
        }
        if (*it == 'D')
        {
            if (*cursor != texto.back())
            {
                texto.erase(++cursor);
                it = texto.erase(it);
                --it;
            }
            else
            {
                it = texto.erase(it);
                --it;
            }
        }

        if (*it == '>')
        {
            if (*cursor != texto.back())
            {
                if (*(std::next(cursor)) == '>')
                {
                    while (it != std::prev(texto.end()))
                    {
                        it = texto.erase(it);
                    }
                    break;
                }

                auto elemento = ++cursor;

                cursor = texto.erase(cursor);
                texto.insert(--cursor, *elemento);

                it = texto.erase(it);

                --it;
                ++count;
            }
            else
            {
                it = texto.erase(it);
                --it;
            }
        }

        if (*it == '<')
        {
            if (*cursor != texto.front())
            {
                auto elemento = --cursor;
                cursor = texto.erase(cursor);
                texto.insert(++cursor, *elemento);
                it = texto.erase(it);
                --it;
                ++count;
            }
            else
            {
                it = texto.erase(it);
                --it;
            }
        }

        if (count >= 1)
        {
            if (std::find(caracteres.begin(), caracteres.end(), *it) != caracteres.end())
            {
                texto.insert(cursor, *it);
                it = texto.erase(it);
                --it;
            }
        }
    }

    Imprimir(texto);
}

int main()
{
    auto texto = create_text();

    edita_texto(texto);

    return 0;
}