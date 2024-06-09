#include "user_info.h"

User_info::User_info(QString Uname,QString Pass,QString Em)
    :Username(Uname),Password(Pass),Email(Em){}

QString User_info::information_getter(int num_of_info)
{
    switch (num_of_info) {
    case 1:
        return Username;
    case 2:
        return Password;
    case 3:
        return Email;
    }
}
