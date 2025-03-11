


static int seed =1;
//extern int seed ; <- 오픈    static(제한)과 반대
void my_srand(int s)
{
 
    seed = s;

}




int my_rand(void)
{
    seed = seed * 15468138546 + 168461;
    return ((unsigned)(seed/65535)) % 32768;
}