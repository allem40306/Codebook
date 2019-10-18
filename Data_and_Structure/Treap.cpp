struct Treap{
    int val, pri, sz;
    Treap *lc, *rc;
    Treap(){}
    Treap(int _val)
    {
        val = _val;
        pri = rand();
        sz = 1;
        lc = rc = NULL;
    }
};

int getSize(Treap *a){
    return (a == NULL ? 0 : a->sz);
}

void split(Treap *t, Treap *&a, Treap *&b, int k)
{
    if(t == NULL)
    {
        a = b = NULL;
        return;
    }
    if(getSize(t->lc) < k)
    {
        a = t;
        split(t->rc, a->rc, b, k - getSize(t->lc) - 1);
    }
    else
    {
        b = t;
        split(t->lc, a, b->lc, k);
    }
}

Treap* merge(Treap *a, Treap *b)
{
    if(!a || !b)
    {
        return (a ? a : b);
    }
    if(a->pri > b->pri)
    {
        a->rc = merge(a->rc, b);
        return a;
    }
    else
    {
        b->lc = merge(a, b->lc);
        return b;
    }
}

void Insert(Treap *&t, int x, int p)
{
    Treap *a, *b;
    split(t, a, b, x);
    t = merge(a, merge(new Treap(p), b));
}

void Delete(Treap *&t, int x)
{
    Treap *a, *b, *c;
    split(t, b, c, x);
    split(b, a, b, x - 1);
    t = merge(a, c);
}

/*
Usage
Treap *root = NULL; // declare
root = merge(root, new Treap(val)); // push back
Insert(root, x, y); // insert y after x-th element
Delete(root, x); // delete x-th element
*/