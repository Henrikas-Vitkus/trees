//darbas
//Pirmas darbas
#include <iostream>
using namespace std;

struct Node
{
    string preke;
    double kaina;
    double svoris;
    Node *Next;
    Node *Previous;
};

Node *head = nullptr;
Node *tail = nullptr;

void choice();
void sarasoPildymas();
void elementuSpausdinimas();
void elementuSpausdinimasIPrieki();
void elementuSpausdinimasAtgal();
void elementuIterpimas();
void iterptiPradzioje();
void iterptiGale();
void iterptiPo();
void elementuTrynimas();
void pirmoElementoTrynimas();
void paskutinioElementoTrynimas();
void pasirinktosPrekesTrynimas();
void rusiavimasPagalKaina();
void rusiavimasNuoMaziausiosKainos();
void rusiavimasNuoDidziausiosKainos();
void rusiavimasPagalSvori();
void rusiavimasNuoMaziausioSvorio();
void rusiavimasNuoDidziausioSvorio();

int main()
{

    choice();
    return 0;
}

void choice()
{
    cout << "1 - Saraso pildymas" << endl;
    cout << "2 - Elementu spausdinimas" << endl;
    cout << "3 - Elementu iterpimas" << endl;
    cout << "4 - Elementu trynimas" << endl;
    cout << "5 - Duomenu rusiavimas pagal kaina" << endl;
    cout << "6 - Duomenu rusiavimas pagal svori" << endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        sarasoPildymas();
        break;
    case 2:
        elementuSpausdinimas();
        break;
    case 3:
        elementuIterpimas();
        break;
    case 4:
        elementuTrynimas();
        break;
    case 5:
        rusiavimasPagalKaina();
        break;
    case 6:
        rusiavimasPagalSvori();
        break;
    }
}

void sarasoPildymas()
{
    // declarinam pirmos prekes values
    string preke1;
    double kaina1;
    double svoris1;
    // declarinam antros prekes values
    string preke2;
    double kaina2;
    double svoris2;
    // declarinam trecios prekes values
    string preke3;
    double kaina3;
    double svoris3;

    // pirma preke
    cout << "Pirma preke:" << endl;
    cin >> preke1;
    cout << "Prekes kaina:" << endl;
    cin >> kaina1;
    cout << "Prekes svoris:" << endl;
    cin >> svoris1;

    // antra preke
    cout << "Antra preke:" << endl;
    cin >> preke2;
    cout << "Prekes kaina:" << endl;
    cin >> kaina2;
    cout << "Prekes svoris:" << endl;
    cin >> svoris2;

    // tecia preke
    cout << "Trecia preke:" << endl;
    cin >> preke3;
    cout << "Prekes kaina:" << endl;
    cin >> kaina3;
    cout << "Prekes svoris:" << endl;
    cin >> svoris3;

    Node *node = new Node();
    node->preke = preke1;
    node->kaina = kaina1;
    node->svoris = svoris1;
    node->Previous = NULL;
    node->Next = NULL;
    head = node;
    tail = node;

    node = new Node();
    node->preke = preke2;
    node->kaina = kaina2;
    node->svoris = svoris2;
    node->Next = NULL;
    node->Previous = tail;
    tail->Next = node;
    tail = node;

    node = new Node();
    node->preke = preke3;
    node->kaina = kaina3;
    node->svoris = svoris3;
    node->Next = NULL;
    node->Previous = tail;
    tail->Next = node;
    tail = node;

    cout << "Elementai uzpildyti" << endl;
    choice();
};

void elementuSpausdinimas()
{
    cout << "1 - I prieki" << endl;
    cout << "2 - Atgal" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        elementuSpausdinimasIPrieki();
        break;
    case 2:
        elementuSpausdinimasAtgal();
        break;
    }
}

void elementuSpausdinimasAtgal()
{
    Node *current = tail;
    while (current != nullptr)
    {
        cout << "Preke: " << current->preke << endl;
        cout << "Kaina: " << current->kaina << "eur" << endl;
        cout << "Svoris: " << current->svoris << "kg" << endl;
        cout << "-------------------" << endl;
        current = current->Previous;
    }
    cout << endl;
    choice();
}

void elementuSpausdinimasIPrieki()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << "Preke: " << current->preke << endl;
        cout << "Kaina: " << current->kaina << "eur" << endl;
        cout << "Svoris: " << current->svoris << "kg" << endl;
        cout << "-------------------" << endl;
        current = current->Next;
    }
    cout << endl;
    choice();
}

void elementuIterpimas()
{
    cout << "1 - Iterpti i prieki" << endl;
    cout << "2 - Iterpti i gala" << endl;
    cout << "3 - Iterpti po x elemento" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        iterptiPradzioje();
        break;
    case 2:
        iterptiGale();
        break;
    case 3:
        iterptiPo();
        break;
    }
}

void iterptiPradzioje()
{
    string prekex;
    double kainax;
    double svorisx;

    cout << "Preke:" << endl;
    cin >> prekex;
    cout << "Prekes kaina:" << endl;
    cin >> kainax;
    cout << "Prekes svoris:" << endl;
    cin >> svorisx;

    Node *node = new Node();
    node->preke = prekex;
    node->kaina = kainax;
    node->svoris = svorisx;
    node->Next = head;
    head->Previous = node;
    head = node;

    cout << "Preke iterpta!" << endl;
    choice();
}

void iterptiGale()
{
    string prekex;
    double kainax;
    double svorisx;

    cout << "Preke:" << endl;
    cin >> prekex;
    cout << "Prekes kaina:" << endl;
    cin >> kainax;
    cout << "Prekes svoris:" << endl;
    cin >> svorisx;

    Node *node = new Node();
    node->preke = prekex;
    node->kaina = kainax;
    node->svoris = svorisx;
    node->Previous = tail;
    tail->Next = node;
    tail = node;

    cout << "Preke iterpta!" << endl;
    choice();
}

void iterptiPo()
{
    string prekePries;
    cout << "Po kurios prekes norite iterpti nauja preke (iveskite prekes pavadinima):" << endl;
    cin >> prekePries;

    string prekex;
    double kainax;
    double svorisx;

    cout << "Nauja preke:" << endl;
    cin >> prekex;
    cout << "Prekes kaina:" << endl;
    cin >> kainax;
    cout << "Prekes svoris:" << endl;
    cin >> svorisx;
    // sukuriame nauja node su vartotojo ivestomis values
    Node *node = new Node();
    node->preke = prekex;
    node->kaina = kainax;
    node->svoris = svorisx;
    node->Next = NULL;
    node->Previous = NULL;

    Node *curr = head;
    // ieskome prekes pagal pavadinima po kurios iterpti nauja preke
    while (curr != NULL && curr->preke != prekePries)
    {
        curr = curr->Next;
    }
    // jei prekes po kurios turejome iterpti nauja preke nera isvedame zinute
    if (curr == NULL)
    {
        cout << "Preke su pavadinimu " << prekePries << " nerasta." << endl;
        choice();
        return;
    }
    // iterpiame nauja preke ir sutvarkome pointerius
    node->Next = curr->Next;
    node->Previous = curr;
    if (curr->Next != nullptr)
    {
        curr->Next->Previous = node;
    }
    curr->Next = node;

    cout << "Preke iterpta!" << endl;
    choice();
}

void elementuTrynimas()
{
    cout << "1 - Pirmos prekes trynimas" << endl;
    cout << "2 - Paskutines prekes trynimas" << endl;
    cout << "3 - Pasirenkamos prekes trynimas" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        pirmoElementoTrynimas();
        break;
    case 2:
        paskutinioElementoTrynimas();
        break;
    case 3:
        pasirinktosPrekesTrynimas();
        break;
    }
}

void pirmoElementoTrynimas()
{
    Node *curr = head;
    head = head->Next;
    head->Previous = NULL;
    delete curr;

    cout << "Pirma preke istrinta!" << endl;
    choice();
}
void paskutinioElementoTrynimas()
{
    Node *curr = tail;
    tail = tail->Previous;
    tail->Next = NULL;
    delete curr;

    cout << "Paskutine preke istrinta!" << endl;
    choice();
}
void pasirinktosPrekesTrynimas()
{
    string trinamaPreke;
    cout << "Kuria preke norite istrinti (prekes pavadinimas):" << endl;
    cin >> trinamaPreke;

    Node *curr = head;
    // jei trinama preke yra pirma perkeliame head vienu i prieki,previous pointeri pointinam i NULL ir istrinam pirma preke
    if (curr->preke == trinamaPreke)
    {
        head = head->Next;
        if (head != NULL)
        {
            head->Previous = NULL;
        }
        delete curr;
        cout << "Preke pavadinimu " << trinamaPreke << " istrinta" << endl;
        choice();
    }
    // einame per prekes kol prieiname NULL arba kol curr->preke yra lygi tinamaPreke
    while (curr != NULL && curr->preke != trinamaPreke)
    {
        curr = curr->Next;
    }
    // jei prieiname NULL isvedame zinute kad tokios prekes nera
    if (curr == NULL)
    {
        cout << "Tokios prekes sarase nera" << endl;
        choice();
    }
    // jei trinama preke yra paskutine, sutvarkom pointerius kad prespaskutines prekes pointeris pointintu i NULL ir istrinam paskutine preke
    if (curr->Next == NULL)
    {
        curr->Previous->Next = NULL;
        delete curr;
        cout << "Preke pavadinimu " << trinamaPreke << " istrinta" << endl;
        choice();
    }
    // jei trinama preke - nei pirma, nei paskutine, sutvarkome pointerius ir istrinam preke
    curr->Previous->Next = curr->Next;
    curr->Next->Previous = curr->Previous;
    delete curr;

    cout << "Preke pavadinimu " << trinamaPreke << " istrinta" << endl;
    choice();
}

void rusiavimasPagalKaina()
{
    cout << "1 - Rusiuoti nuo maziausios iki didziausios kainos" << endl;
    cout << "2 - Rusiuoti nuo didziausios iki maziausios kainos" << endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        rusiavimasNuoMaziausiosKainos();
        break;
    case 2:
        rusiavimasNuoDidziausiosKainos();
        break;
    }
}

void rusiavimasNuoMaziausiosKainos()
{
    Node *current = head;
    // kol priesais esantis node nera NULL tesiame loopa
    while (current->Next != nullptr)
    {
        Node *innerCurrent = current->Next;
        // kol innerCurrent node nera lygus NULL tesiame loopa
        while (innerCurrent != nullptr)
        {
            // jei current nodo kaina yra didesne uz presais ji esancio nodo kaina juos sukeiciame
            if (current->kaina > innerCurrent->kaina)
            {
                // dabartines prekes pavadinima, kaina ir svori storiname i temporary variables
                string tempPreke = current->preke;
                double tempKaina = current->kaina;
                double tempSvoris = current->svoris;
                // preke su mazesne kaina padarome current preke
                current->preke = innerCurrent->preke;
                current->kaina = innerCurrent->kaina;
                current->svoris = innerCurrent->svoris;
                // preke presais gauna value prekes su didesne reiksme
                innerCurrent->preke = tempPreke;
                innerCurrent->kaina = tempKaina;
                innerCurrent->svoris = tempSvoris;
            }
            innerCurrent = innerCurrent->Next;
        }
        current = current->Next;
    }

    cout << "Duomenys surusiuoti nuo maziausios iki didziausios kainos" << endl;
    elementuSpausdinimasIPrieki();
    choice();
}

void rusiavimasNuoDidziausiosKainos()
{
    Node *current = head;
    // kol priesais esantis node nera NULL tesiame loopa
    while (current->Next != nullptr)
    {
        Node *innerCurrent = current->Next;
        // kol innerCurrent node nera lygus NULL tesiame loopa
        while (innerCurrent != nullptr)
        {
            // jei current nodo kaina yra mazesne uz presais ji esancio nodo kaina juos sukeiciame
            if (current->kaina < innerCurrent->kaina)
            {
                // dabartines prekes pavadinima, kaina ir svori storiname i temporary variables
                string tempPreke = current->preke;
                double tempKaina = current->kaina;
                double tempSvoris = current->svoris;
                // preke su didesne kaina padarome current preke
                current->preke = innerCurrent->preke;
                current->kaina = innerCurrent->kaina;
                current->svoris = innerCurrent->svoris;
                // preke presais gauna value prekes su mazesne reiksme reiksme
                innerCurrent->preke = tempPreke;
                innerCurrent->kaina = tempKaina;
                innerCurrent->svoris = tempSvoris;
            }
            innerCurrent = innerCurrent->Next;
        }
        current = current->Next;
    }

    cout << "Duomenys surusiuoti nuo didziausios iki maziausios kainos" << endl;
    elementuSpausdinimasIPrieki();
    choice();
}

void rusiavimasPagalSvori()
{
    cout << "1 - Rusiuoti nuo maziausio iki didziausio svorio" << endl;
    cout << "2 - Rusiuoti nuo didziausio iki maziausio svorio" << endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        rusiavimasNuoMaziausioSvorio();
        break;
    case 2:
        rusiavimasNuoDidziausioSvorio();
        break;
    }
}

void rusiavimasNuoMaziausioSvorio()
{
    Node *current = head;
    // kol priesais esantis node nera NULL tesiame loopa
    while (current->Next != nullptr)
    {
        Node *innerCurrent = current->Next;
        // kol innerCurrent node nera lygus NULL tesiame loopa
        while (innerCurrent != nullptr)
        {
            // jei current nodo svoris yra didesnis uz presais ji esancio nodo svori juos sukeiciame
            if (current->svoris > innerCurrent->svoris)
            {
                // dabartines prekes pavadinima, kaina ir svori storiname i temporary variables
                string tempPreke = current->preke;
                double tempKaina = current->kaina;
                double tempSvoris = current->svoris;
                // preke su mazesniu svoriu padarome current preke
                current->preke = innerCurrent->preke;
                current->kaina = innerCurrent->kaina;
                current->svoris = innerCurrent->svoris;
                // preke presais gauna values prekes su didesniu svoriu
                innerCurrent->preke = tempPreke;
                innerCurrent->kaina = tempKaina;
                innerCurrent->svoris = tempSvoris;
            }
            innerCurrent = innerCurrent->Next;
        }
        current = current->Next;
    }

    cout << "Duomenys surūšiuoti nuo mažiausio iki didžiausio svorio" << endl;
    elementuSpausdinimasIPrieki();
    choice();
}

void rusiavimasNuoDidziausioSvorio()
{
    Node *current = head;
    // kol priesais esantis node nera NULL tesiame loopa
    while (current->Next != nullptr)
    {
        Node *innerCurrent = current->Next;
        // kol innerCurrent node nera lygus NULL tesiame loopa
        while (innerCurrent != nullptr)
        {
            // jei current nodo svoris yra mazesnis uz presais ji esancio nodo svori juos sukeiciame
            if (current->svoris < innerCurrent->svoris)
            {
                // dabartines prekes pavadinima, kaina ir svori storiname i temporary variables
                string tempPreke = current->preke;
                double tempKaina = current->kaina;
                double tempSvoris = current->svoris;
                // preke su didesniu svoriu padarome current preke
                current->preke = innerCurrent->preke;
                current->kaina = innerCurrent->kaina;
                current->svoris = innerCurrent->svoris;
                // preke presais gauna values prekes su mazesniu svoriu
                innerCurrent->preke = tempPreke;
                innerCurrent->kaina = tempKaina;
                innerCurrent->svoris = tempSvoris;
            }
            innerCurrent = innerCurrent->Next;
        }
        current = current->Next;
    }

    cout << "Duomenys surūšiuoti nuo didžiausio iki mažiausio svorio" << endl;
    elementuSpausdinimasIPrieki();
    choice();
}