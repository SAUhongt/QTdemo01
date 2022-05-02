#include "calculator.h"

Calculator::Calculator()
{

}

int Calculator::random(int max)
{
    int temp = -1;
    while(1)
    {
        temp = rand() % (max + 1);
        if(temp != 0)
            return temp;
    }
}

char** Calculator::create(int count, char* coll1, char* coll2, int maxNum, int len, int flag1)
{
    char coll[5];
    strcpy(coll, coll1);
    strcat(coll, coll2);
    srand((unsigned)time(NULL));
    char** eq = (char**)malloc(sizeof(char*) * count);
    int temp = 0;
    int temp1 = 0;
    char str[6] = { 0 };
    for (int i = 0; i < count; i++)
    {
        eq[i] = (char*)malloc(sizeof(char) * 100);
        memset(eq[i], 0, 100);
        int j = 0;
        while (1)
        {
            if(j != 0 && coll[temp] == '/')
                temp = Calculator::random(maxNum + 1);
            else
                temp = rand() % (maxNum + 1);
            itoa(temp, str, 10);
            strcat(eq[i], str);
            if (rand() % 2 && flag1 && len - j - 1 >= 2 && strlen(coll2) != 0)
            {
                temp = rand() % strlen(coll2);
                sprintf(eq[i], "%s%c", eq[i], coll2[temp]);
                strcat(eq[i], "(");
                temp = Calculator::random(maxNum + 1);
                itoa(temp, str, 10);
                strcat(eq[i], str);
                temp = rand() % strlen(coll1);
                sprintf(eq[i], "%s%c", eq[i], coll1[temp]);
                temp1 = Calculator::random(maxNum + 1);
                if(coll1[temp] == '-'){
                    int x = atoi(str);
                    while(x == temp1)
                        temp1 = Calculator::random(maxNum + 1);
                }
                itoa(temp1, str, 10);
                strcat(eq[i], str);
                strcat(eq[i], ")");
                j += 2;
            }
            j++;
            if (j >= len)
                break;
            temp = rand() % strlen(coll);
            sprintf(eq[i], "%s%c", eq[i], coll[temp]);
        }
    }
    return eq;
}

int Calculator::handle(char* eq)
{
    stack<char> ope;
        stack<int> numb;
        ope.push('#');
        char cur = '#';
        for (int i = 0; i < strlen(eq); i++)
        {
            if (eq[i] == ' ')
                continue;
            else if (eq[i] >= 48 && eq[i] <= 57) {
                char str[6] = { 0 };
                sprintf(str, "%s%c", str, eq[i]);
                while (i < strlen(eq) && (eq[i + 1] >= 48 && eq[i + 1] <= 57)) {
                    sprintf(str, "%s%c", str, eq[++i]);
                }
                numb.push(atoi(str));
            }
            else if (eq[i] == '(')
                ope.push('#');
            else
            {
                if (eq[i] == ')')
                {
                    cur = ope.top();
                    ope.pop();
                    if (cur == '#')
                        continue;
                    int y = numb.top();
                    numb.pop();
                    int x = numb.top();
                    numb.pop();
                    int temp = cal(cur, 1, x, y);
                    numb.push(temp);
                    ope.pop();
                }
                cur = ope.top();
                if (cal(cur) < cal(eq[i]))
                    ope.push(eq[i]);
                else
                {
                    cur = ope.top();
                    while (cal(cur) >= cal(eq[i]) && numb.size() > 1)
                    {
                        int y = numb.top();
                        numb.pop();
                        int x = numb.top();
                        numb.pop();
                        int temp = cal(cur, 1, x, y);
                        numb.push(temp);
                        ope.pop();
                        cur = ope.top();
                    }
                    if (eq[i] != ')')
                        ope.push(eq[i]);

                }
            }

        }
        while (ope.size() > 1)
        {
            cur = ope.top();
            ope.pop();
            int y = numb.top();
            numb.pop();
            int x = numb.top();
            numb.pop();
            numb.push(cal(cur, 1, x, y));
        }
        return numb.top();
}

int Calculator::cal(char c, int flag, int x, int y) {
    if (c == '#')
        return 0;
    if (c == '+')
    {
        if (flag)
            return x + y;
        return 1;
    }
    if (c == '-')
    {
        if (flag)
            return x - y;
        return 1;
    }
    if (c == '*')
    {
        if (flag)
            return x * y;
        return 2;
    }
    if (c == '/')
    {
        if (flag)
        {
            return x / y;
        }
        return 2;
    }
    return 0;
}
