#include <iostream>
#include <vector>

using namespace std;

void traducir(vector<string> text);

int main() {
    vector<string> texto;
    string inp = "aa";
    while(inp!="")
    {
        getline(cin, inp);
        texto.push_back(inp);
    }
    traducir(texto);
}

void traducir(vector<string> text)
{
    bool izq = true;
    bool cambiado = false;
    for(int i = 0; i<text.size();i++)
    {
        for(int j = 0; j<text[i].size();j++)
        {
            if(text[i][j]=='\"')
            {
                if(izq)
                {
                    text[i][j] = '`';
                    izq = false;
                    cambiado = true;
                }
                else
                {
                    text[i][j] = '\'';
                    izq = true;
                    cambiado = true;
                }
            }
            cout<<text[i][j];
            if(cambiado && !izq)
            {
                cout<<'`';
                cambiado = false;
            }
            if(cambiado && izq)
            {
                cout<<'\'';
                cambiado = false;
            }
        }
        if(i != text.size()-1)
        cout<<endl;
    }
}

