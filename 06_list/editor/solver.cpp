#include <iostream>
#include <algorithm>
#include <list>

void Show(std::list<char> &texto)
{
    for (auto &elemento : texto)
        std::cout << elemento;
}

void Editar(std::list<char> &texto)
{
    auto cursor = texto.begin();
    int count = 0;

    for (auto it = texto.begin(); it != texto.end(); it++)
    {
        for (auto it = texto.begin(); it != texto.end(); it++)
        {
            if (*it == '|')
                cursor = it;
        }

        if (*it == 'B')
        {
            if (*cursor != texto.front())
            {
                cursor = texto.erase(--cursor);
                it = texto.erase(it);
                --it;
            }
            it = texto.erase(it);
            --it;
        }

        if (*it == 'R')
            *it = '\n';

        if (*it == 'D')
        {
            if (*cursor != texto.back())
            {
                texto.erase(++cursor);
                it = texto.erase(it);
                --it;
            }
            it = texto.erase(it);
            --it;
        }

        if (*it == '>')
        {
            if (*cursor != texto.back())
            {
                if (*(std::next(cursor)) == '>')
                {
                    while (it != std::prev(texto.end()))
                        it = texto.erase(it);
                    break;
                }

                auto elemento = ++cursor;
                cursor = texto.erase(cursor);
                texto.insert(--cursor, *elemento);
                it = texto.erase(it);
                --it;
                ++count;
            }
            it = texto.erase(it);
            --it;
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
            it = texto.erase(it);
            --it;
        }
    }

    Show(texto);
}

int main()
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

        if (it + 1 == line.end() && count == 0)
            texto.push_back('|');

        texto.push_back('\n');
        break;
    }

    Editar(texto);

    return 0;
}