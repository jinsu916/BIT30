using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _1029
{
    //고객리스트
    public class Acclist : ObservableCollection<Account>
    {
        public Acclist()
        {
            Add(new Account() { Id = 0001, Name = "가가가", Balance = 9000, Joindate = DateTime.Now });
            Add(new Account() { Id = 0002, Name = "나나나", Balance = 2000, Joindate = DateTime.Now });
            Add(new Account() { Id = 0003, Name = "다다다", Balance = 3000, Joindate = DateTime.Now });
        }
    }

    public partial class MainWindow : Window
    {
        Account acc = null;

        public MainWindow()
        {
            InitializeComponent();
            //panel.DataContext = acc; 

            acc = (Account)FindResource("account");
        }

        #region 입력 수정 삭제
        private void DeleteButton_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("acclist"));
            Account acc = (Account)view.CurrentItem;

            int idx = acciolist.Items.Count - 1;
            int count = acciolist.Items.Count;

            for (int i = 0; i < count; i++)
            {
                string str = acciolist.Items[idx].ToString();
                bool b = str.Contains("계좌ID:" + acc.Id.ToString());

                if (b == true)
                {
                    acciolist.Items.RemoveAt(idx);
                    idx -= 1;
                }
                else if (b == false)
                {
                    idx -= 1;
                }
            }

            Acclist acclist = (Acclist)FindResource("acclist");
            if (listBox.SelectedIndex >= 0)
            {
                acclist.RemoveAt(listBox.SelectedIndex);
            }
        }

        private void InsertButton_Click(object sender, RoutedEventArgs e)
        {
            Acclist acclist = (Acclist)FindResource("acclist");

            Account newacc = new Account()
            {
                Id = acc.Id,
                Name = acc.Name,
                Balance = acc.Balance,
                Joindate = DateTime.Now
            };
            acclist.Add(newacc);
            
        }

        private void UpdateButton_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("acclist"));
            Account acc = (Account)view.CurrentItem;
            acc.Id = int.Parse(id.Text);
            acc.Name = name.Text;
            acc.Balance = int.Parse(balance.Text);
        }
        #endregion

        #region 검색 정렬
        private void FilterButton_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("acclist"));
            if(view.Filter == null)
            {
                view.Filter = delegate (object obj)
                {
                    if (filtercombo.Text == "이름")
                    {
                        return listboxtext.Text == ((Account)obj).Name;
                    }
                    else if (filtercombo.Text == "계좌번호")
                    {
                        return ((Account)obj).Id == int.Parse(listboxtext.Text);
                    }
                    else if (filtercombo.Text == "잔액")
                    {
                        return ((Account)obj).Balance >= int.Parse(listboxtext.Text);
                    }
                    else
                    {
                        return true;
                    }
                };
            }
            else
            {
                view.Filter = null;
            }
        }

        private void Sort_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("acclist"));

            if (view.SortDescriptions.Count == 0)
            {

                if (filtercombo.Text == "이름")
                {
                    view.SortDescriptions.Add(new SortDescription("Name", ListSortDirection.Ascending));
                }
                else if (filtercombo.Text == "계좌번호")
                {
                    view.SortDescriptions.Add(new SortDescription("Id", ListSortDirection.Ascending));
                }
                else if (filtercombo.Text == "잔액")
                {
                    view.SortDescriptions.Add(new SortDescription("Balance", ListSortDirection.Ascending));
                }
                else
                {

                }
            }
            else
            {
                view.SortDescriptions.Clear();
            }
        }
        #endregion

        #region 입금 출금
        private void Inputmoney_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("acclist"));
            Account acc = (Account)view.CurrentItem;
            Accio acio = new Accio();

            acio.Inputmoney = int.Parse(money.Text);
            acc.Balance += int.Parse(money.Text);

            Accio newperson = new Accio()
            {
                Accioid = acc.Id,
                Inputmoney = acio.Inputmoney,
                Outputmoney = 0,
                Tradtime = DateTime.Now
            };

            acciolist.Items.Add(newperson);
        }

        private void Outputmoney_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("acclist"));
            Account acc = (Account)view.CurrentItem;
            Accio acio = new Accio();

            acio.Outputmoney = int.Parse(money.Text);
            Accio newperson = new Accio()
            {
                Accioid = acc.Id,
                Inputmoney = 0,
                Outputmoney = acio.Outputmoney,
                Tradtime = DateTime.Now
            };
            if (acc.Balance >= acio.Outputmoney)
            {
                acc.Balance -= acio.Outputmoney;
                acciolist.Items.Add(newperson);
            }
            else
            {
                MessageBox.Show("돈이없음");
            }
        }
        #endregion
    }
}
