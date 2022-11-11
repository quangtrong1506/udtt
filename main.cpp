#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct CongViec
{
    /* data */
    int maCV;
    int batDau;
    int ketThuc;
    CongViec() {}

    CongViec(int maCV, int batDau, int ketThuc)
    {
        this->maCV = maCV;
        this->batDau = batDau;
        this->ketThuc = ketThuc;
    }
    void out()
    {
        cout << "\n"
             << this->maCV << " " << this->batDau << " " << this->ketThuc;
    }
};
int tong = 0;
vector<CongViec> cvs;
void tinhTong(int i)
{

    if (i != cvs.size())
    {
        tong += cvs[i].ketThuc - cvs[i].batDau;

        tinhTong(i + 1);
    }
}
vector<CongViec> cc;
void thucHien()
{
    // cc.push_back(cvs[0]);
    int i = 0;
    int kt = 0;

    while (i < cvs.size())
    {

        vector<CongViec> vc1;
        for (int j = i; j < cvs.size(); j++)
        {
            if (cvs[j].batDau >= kt)
            {

                vc1.push_back(cvs[j]);
            }
        }

        if (vc1.size() != 0)
        {
            int p = 0;
            int min = vc1[0].ketThuc;
            for (size_t j = 0; j < vc1.size(); j++)
            {
                if (min > vc1[j].ketThuc)
                {
                    min = vc1[j].ketThuc;
                    p = j;
                }
            }
            // vc1[p].out();

            cc.push_back(vc1[p]);

            for (size_t j = 0; j < cvs.size(); j++)
            {
                if (cvs[j].maCV == vc1[p].maCV)
                {
                    i = j;
                    kt = cvs[j].ketThuc;
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
}

void next_config(int x[], int k, int i)
{
    x[i] += 1;
    i++;
    while (i <= k)
    { // x[i+1], …, x[k] = can duoi
        x[i] = x[i - 1] + 1;
        i++;
    }
}
void view_config(int x[], int k)
{
    for (int i = 1; i <= k; i++)
        cout << x[i] << " ";
    cout << endl;
}

void listing_configs(int k, int n)
{
    int i, x[k + 1] = {0};
    // Cau hinh dau tien {1 2 … k}
    for (i = 1; i <= k; i++)
    {
        x[i] = i;
    }
    do
    {
        view_config(x, k);
        i = k;
        while (i > 0 && x[i] == n - k + i)
            i--;
        if (i > 0)
        {
            next_config(x, k, i);
        }
    } while (i > 0);
}
void sort()
{
    for (size_t i = 0; i < cvs.size() - 1; i++)
    {
        int min = cvs[i].ketThuc;
        int p = i;
        for (size_t j = i + 1; j < cvs.size(); j++)
        {
            if (min > cvs[j].ketThuc)
            {
                p = j;
                min = cvs[j].ketThuc;
            }
        }
        CongViec c = cvs[i];
        cvs[i] = cvs[p];
        cvs[p] = c;
    }
}
int main()
{
    /* code */

    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        CongViec c;
        cin >> c.maCV >> c.batDau >> c.ketThuc;
        cvs.push_back(c);
    }
    sort();

    cout << "Tong thoi gian: ";
    tinhTong(0);
    cout << tong << "\n";

    cout << "Danh sach cong viec nhieu nhat: ";
    thucHien();

    for (size_t i = 0; i < cc.size(); i++)
    {
        cc[i].out();
    }
    cout << "\n";
    cout << "Danh sach lay ra 5 cong viec:\n";
    listing_configs(5, cvs.size());

    return 0;
}
