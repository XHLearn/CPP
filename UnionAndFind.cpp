/*
 * @Description: 并查集
 * @Author: lamborghini1993
 * @Date: 2019-02-21 15:56:43
 * @UpdateDate: 2019-02-21 16:26:14
 */

class UnionAndFind
{
  protected:
    int parent[];
    int r;

  public:
    UnionAndFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int Find(int p)
    {
        r = p;
        while (r != parent[r])
        {
            r = parent[r];
        }
        while (parent[p] != r)
        {
            parent[p] = r;
            p = parent[p];
        }
        return r;
    }

    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if (x == y)
            return;
        parent[x] = y;
    }
};

int main()
{
    return 0;
}