#include "cub3d.h"

//static int tanımlanmış neden !!!
int horizontal_check(char **map)
{
    int i;
    int j;
    int flag;

    i = -1;
    
    while (map[++i])
    {
        j = -1;
        flag = 0;

        while (map[i][++j])
        {
            if (flag == 0 && map[i][j] == '1')
                flag = !flag;
            
            if (flag == 0 && ft_strchr("NESW0", map[i][j]))
                return (0);
            
            if (flag == 1 && map[i][j] == ' ')
            {
                if (map[i][j - 1] && ft_strchr("NESW0", map[i][j - 1]))
                    return (0);
                flag = !flag;
            }
        }
    }
    

    return (1);
}

int map_check(char **map)
{
    if (!horizontal_check(map))
        return (0);
    
    if (!vertical_check(map))
        return (0);
    
    return (1);
}