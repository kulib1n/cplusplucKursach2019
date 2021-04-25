#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

struct Sudoku
{
    int row_col = 9;
    char arr[9][9];
    string vvod;
    int arr_1[9][9]{{2,3,8,9,6,5,7,1,4},
                    {7,5,9,4,1,3,6,8,2},
                    {4,1,6,2,7,8,9,5,3},
                    {9,4,5,1,3,6,2,7,8},
                    {6,8,7,5,2,4,1,3,9},
                    {3,2,1,8,9,7,4,6,5},
                    {1,6,2,3,5,9,8,4,7},
                    {5,7,4,6,8,2,3,9,1},
                    {8,9,3,7,4,1,5,2,6}};
    bool check_choice(int a)
    {
        return a!=1&&a!=2&&a!=3&&a!=12345;
    }
    Sudoku()
    {
        int lvl_hard = 0;
        int choice = 0;
        while(check_choice(choice))
        {
            cout << "\
            \nPlease, chose difficulty:\
            \n1) Easy\
            \n2) Normal\
            \n3) Hard" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                lvl_hard = 20;
                break;
            case 2:
                lvl_hard = 40;
                break;
            case 3:
                lvl_hard = 60;
                break;
            case 12345:
                lvl_hard = 1;
                break;
            default:
                break;
            }

        }
        int counter = 0;
        for (int i = 0;i < row_col ;++i )
        {
            for (int j = 0;j < row_col ;++j )
            {
                arr[i][j]=arr_1[i][j]+48;
            }
        }
        int j = 0;
        for (int i = 0;counter < lvl_hard;)
        {
            j = rand()%9;
            i = rand()%9;
            arr[i][j]='#';
            ++counter;
        }
    }


    void print()
    {
        cout << "O 1 2 3  4 5 6  7 8 9" << endl;
        for (int i = 1;i < row_col+1 ;++i)
        {
            if((i-1)%3==0)
                {
                    cout << "  ---------------------" << endl;
                }
                cout << i<<"|";
            for (int j = 0;j < row_col ;++j )
            {
                cout << arr[i-1][j] << " ";
                if((j+1)%3==0)
                {
                    cout << "|";
                }
            }
            cout << endl;
        }
        cout << "  ---------------------" << endl;
    }

    bool check_row_col(string a)
    {
        for (int i = 0;i < row_col ;++i )
        {
            if(a[5]==arr[(a[1]-49)][i]||a[5]==arr[i][(a[3]-49)])
            {
                return false;
            }
        }
        return true;
    }

    bool check_kvadr(string a)
    {
        int i_start = (a[1]-49)/3;
        i_start*=3;
        int j_start = (a[3]-49)/3;
        j_start*=3;
        for (int i = i_start; i < i_start+3 ;++i )
        {
            for (int j = j_start; j < j_start+3 ;++j )
            {
                if(a[5]==arr[i][j])
                {
                    return false;
                }
            }
            return true;
        }
    }
    void create_el(string a)
    {
        arr[(a[1]-49)][(a[3]-49)] = a[5];
    }
    void delete_el(string a)
    {
        arr[(a[1]-49)][(a[3]-49)] = '#';
    }
    bool game_end()
    {
        for (int i = 0;i < 9;++i)
        {
            for (int j = 0;j< 9;++j)
            {
                if(arr[i][j]=='#')
                {
                    return false;
                }
            }
        }
        return true;
    }
};

bool game(Sudoku abc)
{
    system("cls");
    cout << "Rules:\n\
    \tC- Create element\n\
    \tD - Delete element\n\
    \tX - 1st coordinate\n\
    \tY - 2nd coordinate\n\
    \tA - Your number\n\
    \tCorrect form: CX,Y_A\n\
    \tFor example: C5,6_2 - create 2 on coordinates x=5, y=6\n\
    \tFor example: D1,1 - delete element on coordinates x=1, y=1" << endl;
    while(1)
    {

        abc.print();
        cin >> abc.vvod;
        switch (abc.vvod[0])
            {
            case 'C':
                if(abc.check_kvadr(abc.vvod)&&abc.check_row_col(abc.vvod)&&abc.vvod[5]>48&&abc.vvod[5]<58)
                {
                    abc.create_el(abc.vvod);
                }
                cout << endl;
                break;
            case 'D':
                abc.delete_el(abc.vvod);
                cout << endl;
                break;
            default:
                cout << " Ty shto-to nepravilno vvel" << endl;
                Sleep(2000);
                break;
            }

            system("cls");
            if(abc.game_end())
            {
                cout << "Congratulations! YOU WIN!!!"<< endl;
                break;
            }
    }

}


int main()
{
    srand(time(NULL));
    Sudoku a;
    game(a);
    return 0;
}
