#include <iostream>

int main(int argc, char **argv)
{
    int i,k;
    i=0;
    if(argc==1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        k=0;
        i++;
        while(argv[i][k])
        {
            if(argv[i][k] >= 'a' && argv[i][k] <= 'z')
                argv[i][k] -= 32;
            std::cout << argv[i][k];
            k++;
        }
            std::cout << std::endl;
            i++;
    }

}