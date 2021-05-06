#include"GRAPHS.h"

void SinglyList::push_back(int info)
    {
        if (this->root == NULL)
        {
            Node* newnode = new Node;
            this->root = newnode;
            this->last = newnode;
            newnode->link = NULL;
            newnode->info = info;
        }
        else
        {
            Node* newnode = new Node;
            newnode->link = NULL;
            last->link = newnode;
            last = newnode;
            newnode->info = info;
            newnode->link = NULL;
        }
        this->size++;
    }

void SinglyList::traverse()
    {
        Node* temp = this->root;
        while (temp != NULL)
        {
            if (temp->link != NULL)
                cout << temp->info << "  ";
            else
                cout << temp->info << "  ";
            temp = temp->link;
        }
        cout << endl;
    }

int SinglyList::begin()
    {
        return 0;
    }

int SinglyList::end()
    {
        return this->size;
    }

SinglyList::SinglyList()
    {
        this->last = NULL;
        this->root = NULL;
        this->size = 0;
    }

SinglyList::~SinglyList()
    {
        delete this->root;
        delete this->last;
    }


//-------------TOTAL CYCLES IN GRAPH-------------//


CYCLES::Graph(int A)
{
    this->V = V;
    A = new list<int>[V];
}

void CYCLES::INSERT(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool CYCLES::CHECK_CONDITIONS(int v, bool visited[], int parent)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            if (isCyclicUtil(*i, visited, v)) {
                cycleNumber += 1;
                return true;
            }
        }

        else if (*i != parent) {
            cycleNumber += 1;
            return true;
        }
    }
    return false;
}

bool CYCLES::COUNT_CYCLES()
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (CHECK_CONDITIONS(i, visited, -1))
            {
                return true;
            }
        }
    }
    return false;
}

void CYCLES::READ_DATA()
{

    int  from, to;
    int w, temp;
    read.open("DATA.txt");
    if (read.is_open())
    {
        read >> temp;
        V = temp;

        cout << " Total vertices : " << V << endl;

        do
        {
            read >> from;
            read >> to;

            INSERT(from, to);
        } while (!read.eof());
    }
    else if (!read)
    {
        cout << "Cannot open file.\n";
    }
    read.close();

}

//-----------------BIPARTITE GRAPH-----------------//

BIPARTITE::BIPARTITE()
{
     ifstream read;
     read.open("DATA.txt");
     int Ver;
     read >> Ver;
     this->numberOfVertices = Ver;
     graph = new int*[this->numberOfVertices];
     for (int i = 0; i < this->numberOfVertices; i++)
         this->graph[i] = new int[numberOfVertices];
}
void BIPARTITE::READ_DATA()
{
    int  from, to, total_vertices;

    read.open("DATA.txt");
    if (read.is_open())
    {
        read >> total_vertices;
        V = total_vertices;

        cout << "\n Total vertices : " << V << endl;

        GRAPH_INITIALIZATION();

        cout << "\n From\t" << "To\n\n";

        do
        {
            read >> from;
            read >> to;

            graph[from][to] = graph[to][from] = 1;

            cout << " " << from << "\t" << to;
            cout << endl;
        } while (!read.eof());
    }
    else if (!read)
    {
        cout << "Cannot open file." << endl;
    }
    read.close();
    DISPLAY_GRAPH();
}

void BIPARTITE::GRAPH_INITIALIZATION()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void BIPARTITE::DISPLAY_GRAPH()
{
    cout << "\n\n\tGRAPH REPRESENTATION\n\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << " " << graph[i][j] << "\t";
        }
        cout << endl;
    }
}

bool BIPARTITE::TO_CHECH_IF_BIPARTITE(int S)
{

    int arr[5];
    for (int i = 0; i < V; ++i)
        arr[i] = -1;

    arr[S] = 1;

    queue <int> Q1;
    Q1.push(S);

    while (!Q1.empty())
    {
        int X = Q1.front();
        Q1.pop();

        if (graph[X][X] == 1)
            return false;

        for (int i = 0; i < V; ++i)
        {

            if (graph[X][i] && arr[i] == -1)
            {
                arr[i] = 1 - arr[X];
                Q1.push(i);
            }

            else if (graph[X][i] && arr[i] == arr[X])
                return false;
        }
    }
    return true;
}

void BIPARTITE::DISPLAY_RESULT()
{
    if (TO_CHECH_IF_BIPARTITE(1))

        cout << "\n\nYes, the given graph is Bipartite.\n";

    else
        cout << "\n\nNo, the given graph is not bipartite.\n";
}

//-------------KRUSKALS ALGORITHM-------------//


KRUSKALS::KRUSKALS()
{
     ifstream read;
     read.open("P-K.txt");
     int Ver;
     read >> Ver;
     this->numberOfVertices = Ver;
     graph = new int* [this->numberOfVertices];
     for (int i = 0; i < this->numberOfVertices; i++)
         this->graph[i] = new int[numberOfVertices];
}

int* KRUSKALS::getVertices(int& numberofVertices, string filename)
{
    ifstream input;
    input.open(filename);
    if (!input.is_open())
    {
        cout << "FILE NOT FOUND" << endl;
        exit(0);
    }

    input >> numberofVertices;
    int value = 0;
    int* vertices = new int[numberofVertices];
    bool* visited = new bool[numberofVertices];
    for (int i = 0; i < numberofVertices; i++)
        visited[i] = false;

    while (input.good())
    {
        input >> value;
        for (int i = 0; i < numberofVertices; i++)
        {
            if (value <= numberofVertices && visited[value] == false)
            {
                visited[value] = true;
                vertices[value] = value;
            }
        }
    }
    return vertices;
}

void KRUSKALS::READ_DATA()
{
    char  from[10], to[10];
    int weight, total_vertices, x, y;
    read.open("P-K.txt");
    if (read.is_open())
    {
        read >> total_vertices;
        V = total_vertices;

        cout << "\nTotal vertices : " << V << endl;

        GRAPH_INITIALIZATION();

        cout << "\nEnter vertices : \n";
        for (int i = 0; i < V; ++i)
            cin >> mst[i];

        cout << "\nTotal Edges :\n\n";
        cout << "\nFrom\t" << "To\t" << "Weight\n\n";
        do
        {
            read >> from;
            read >> to;
            read >> weight;

            x = SET_PLACE(from);
            y = SET_PLACE(to);

            graph[x][y] = graph[y][x] = weight;

            cout << " " << from << "\t" << to << "\t" << weight;
            cout << endl;
        } while (!read.eof());
    }
    else if (!read)
    {
        cout << "Cannot open file." << endl;
    }
    read.close();
    DISPLAY_GRAPH();
}

void KRUSKALS::GRAPH_INITIALIZATION()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            graph[i][j] = infinity;
        }
    }
}

void KRUSKALS::DISPLAY_GRAPH()
{

    cout << "\n\n  GRAPH REPRESENTATION\n\n";
    for (i = 0; i < V; ++i)
    {
        for (j = 0; j < V; ++j)
        {
            cout << " " << graph[i][j] << "\t";
        }
        cout << endl;
    }
}

int KRUSKALS::SET_PLACE(char data[10])
{
    for (i = 0; i < V; ++i)
        if (strcmp(mst[i], data) == 0)
            return i;
    return -1;
}

void KRUSKALS::MST()
{
    int  arr[10] = { 0 }, total_cost = 0, flag = false;
    int a, b, minimum_value, Z = 1, C;

    cout << "\n\n\n  MINIMUN SPANNING TREE USING KRUSKAL'S ALGORITHM\n\n";
    cout << "\nFrom   To\tWeight\n";

    while (flag == false)
    {
        minimum_value = 999;

        for (i = 0; i < V; ++i)
        {
            for (j = 0; j < V; ++j)
            {
                if (graph[i][j] < minimum_value)
                {
                    minimum_value = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        CHECK_CONDITIONS(arr, a, b, Z);

        graph[a][b] = graph[b][a] = 999;
        total_cost += minimum_value;

        DISPLAY_MST(a, b, minimum_value);

        C = arr[0];
        flag = true;

        for (i = 0; i < V; ++i)
        {
            if (C != arr[i])
            {
                flag = 0;
                break;
            }
        }
    }
    cout << "\n\nTotal cost of MST : " << total_cost << endl << endl;
}

void KRUSKALS::CHECK_CONDITIONS(int arr[], int a, int b, int Z)
{
    int S;
    if (arr[a] == 0 && arr[b] == 0)
    {
        arr[a] = arr[b] = Z;
        Z++;
    }
    else if (arr[a] != 0 && arr[b] == 0)
    {
        arr[b] = arr[a];
    }
    else if (arr[a] == 0 && arr[b] != 0)
    {
        arr[a] = arr[b];
    }
    else
    {
        if (arr[a] != arr[b])
        {
            S = arr[a];
            for (i = 0; i < V; ++i)
            {
                if (arr[i] == S)
                    arr[i] = arr[b];
            }
        }
    }
}

void KRUSKALS::DISPLAY_MST(int a, int b, int minimum_value)
{
    cout << "\n  " << mst[a] << " -> " << mst[b] << "\t" << minimum_value;
}

//-------------PRIMS ALGORITHM-------------//



    
PRIMS::PRIMS()
    {
        ifstream read;
        read.open("P-K.txt");
        int Ver;
        read >> Ver;
        this->numberOfVertices = Ver;

        graph = new int* [this->numberOfVertices];
        for (int i = 0; i < this->numberOfVertices; i++)
            this->graph[i] = new int[numberOfVertices];
    }

void PRIMS::READ_DATA()
    {
        int  from, to;
        int weight, total_vertices;

        read.open("P-K.txt");

        if (read.is_open())
        {
            read >> total_vertices;
            V = total_vertices;

            cout << "\n Total vertices : " << V << endl;

            INITIALIZE_GRAPH();

            cout << "\n Total edges :\n";
            cout << "\n From\t" << "To\t" << "Weight\n\n";
            do
            {
                read >> from;
                read >> to;
                read >> weight;

                graph[from][to] = graph[to][from] = weight;

                cout << " " << from << "\t" << to << "\t" << weight;
                cout << endl;
            } while (!read.eof());
        }
        else if (!read)
        {
            cout << "Cannot open file." << endl;
        }
        read.close();
        DISPLAY_GRAPH();
    }

void PRIMS::INITIALIZE_GRAPH()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                graph[i][j] = 0;
            }
        }
    }

int PRIMS::MINIMUM(int data[], bool ST[])
    {
        int min_value = INT_MAX, smallest_index;

        for (int i = 0; i < V; ++i)
        {
            if (ST[i] == false && data[i] < min_value)
                min_value = data[i], smallest_index = i;
        }

        return smallest_index;
    }

void PRIMS::SPANNING_TREE()
    {
        bool ST[7];
        int G[7];
        int data[7];

        for (int i = 0; i < V; ++i)

            data[i] = INT_MAX, ST[i] = false;

        data[0] = 0;
        G[0] = -1;

        SET_VERTICES(data, G, ST);

        DISPLAY_MST(G);
    }

void PRIMS::SET_VERTICES(int data[], int G[], bool ST[])
    {
        for (int i = 0; i < V - 1; ++i)
        {
            int X = MINIMUM(data, ST);

            ST[X] = true;

            for (int i = 0; i < V; ++i)

                if (graph[X][i] && ST[i] == false && graph[X][i] < data[i])
                    G[i] = X, data[i] = graph[X][i];
        }
    }

void PRIMS::DISPLAY_GRAPH()
    {
        cout << "\n\n\tGRAPH REPRESENTATION\n\n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << " " << graph[i][j] << "\t";
            }
            cout << endl;
        }
    }

void PRIMS::DISPLAY_MST(int G[])
    {

        int cost = 0;
        cout << "\n\n    MINIMUM SPANNING TREE USING PRIM'S ALGORITHM\n\n";
        cout << " Edges \t\tWeights\n\n";
        for (int i = 1; i < V; i++)
        {
            cout << " " << G[i] << "->" << i << "\t\t" << graph[i][G[i]] << " \n";
            cost += graph[i][G[i]];
        }

        cout << "\nTotal cost of MST: " << cost << endl;

    }


//-------------EULER CIRCUIT & EULER PATH-------------//


EULER_PATH::EULER_PATH()
    {
        ifstream read;
        read.open("DATA.txt");
        int Ver;
        read >> Ver;
        this->numberOfVertices = Ver;

        graph = new int* [this->numberOfVertices];
        for (int i = 0; i < this->numberOfVertices; i++)
            this->graph[i] = new int[numberOfVertices];
    }
EULER_PATH::EULER_PATH(int V)
    {
        this->V = V;
        A = new list<int>[V];
    }

EULER_PATH::~EULER_PATH()
    {
        delete[] A;
    }

void EULER_PATH::INSERT(int x, int y)
    {
        A[x].push_back(y);
        A[y].push_back(x);
    }

void EULER_PATH::DISPLAY_EULER_PATH()
    {
        cout << "\n\n  EULER PATH OF GRAPH\n\n";
        int X = 0;
        for (int i = 0; i < V; i++)
            if (A[i].size() & 1)
            {
                X = i;
                break;
            }
        EULER(X);
        cout << endl;
    }

void EULER_PATH::EULER(int z)
    {
        list<int>::iterator i;
        for (i = A[z].begin(); i != A[z].end(); ++i)
        {
            int S;
            S = *i;

            if (S != -1 && CHECK_NEXT(z, S))
            {
                cout << " " << z << "-" << S << "  ";
                EDGE(z, S);
                EULER(S);
            }
        }
    }

bool EULER_PATH::CHECK_NEXT(int a, int b)
    {
        int count = 0;
        list<int>::iterator i;
        for (i = A[a].begin(); i != A[a].end(); ++i)
            if (*i != -1)
                count++;

        if (count == 1)
            return true;

        bool visited[4];
        memset(visited, false, V);
        int count1 = DFS(a, visited);

        EDGE(a, b);
        memset(visited, false, V);
        int count2 = DFS(a, visited);

        INSERT(a, b);

        return (count1 > count2) ? false : true;
    }

void EULER_PATH::EDGE(int x, int y)
    {

        list<int>::iterator iv = find(A[x].begin(), A[x].end(), y);
        *iv = -1;

        list<int>::iterator iu = find(A[y].begin(), A[y].end(), x);
        *iu = -1;
    }

int EULER_PATH::DFS(int v, bool visited[])
    {

        visited[v] = true;
        int count = 1;

        list<int>::iterator i;
        for (i = A[v].begin(); i != A[v].end(); ++i)
            if (*i != -1 && !visited[*i])
                count += DFS(*i, visited);

        return count;
    }

void EULER_PATH::GRAPH_INITIALIZATION()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                graph[i][j] = 0;
            }
            cout << endl;
        }
    }

void EULER_PATH::READ_DATA()
    {

        int  from, to;
        int w, temp;
        GRAPH_INITIALIZATION();
        read.open("DATA.txt");
        if (read.is_open())
        {
            read >> temp;
            V = temp;

            cout << " Total vertices : " << V << endl;
            cout << "\n Edges : \n\n";

            do
            {
                read >> from;
                read >> to;

                INSERT(from, to);
                graph[from][to] = graph[to][from] = 1;
                cout << " " << from << "-" << to;
                cout << endl;
            } while (!read.eof());
        }
        else if (!read)
        {
            cout << "Cannot open file.\n";
        }
        read.close();
        DISPLAY_GRAPH();
    }

void EULER_PATH::DISPLAY_GRAPH()
    {
        cout << "\n\n   GRAPH REPRESENTATION\n\n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << " " << graph[i][j] << "\t";
            }
            cout << endl;
        }
    }