#include <stdio.h>
#include <string.h>

void Dstring(const char *in)
{
    int l = strlen(in);
    int i = 0;
    int j = l - 1;
    int flag = 1;

    while (i < j)
    {
        if (in[i] != in[j])
        {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if (flag)
    {
        printf("p");
        for (int i = 0; i < l; i++)
        {
        if (in[i] == '0' && in[l - 1] == '0')
        {
            printf(" => 0P0");
        }
        else if (in[i] == '1' && in[l - 1] == '1')
        {
            printf(" => 1P1");
        }
        }
        printf(" => %s\n", in);
    }
    else
    {
        printf("not in this grammar");
    }
}
int main()
{
    const char *in1 = "010";
    const char *in2 = "10101";
    const char *in3 = "101010";

    Dstring(in1);
    Dstring(in2);
    Dstring(in3);

    return 0;
}