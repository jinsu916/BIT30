using System;
using System.Collections.Generic;
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
using System.Windows.Shapes;

namespace _1028
{
    /// <summary>
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {
        //private Person per = new Person()
        //{
        //    Name = "홍길동",
        //    Phone = "010-1111-1234",
        //    Age = 22
        //};
        Person per = null;

        public Window1()
        {
            InitializeComponent();

            //pannel.DataContext = per;
            per = (Person)FindResource("person");

            Validation.AddErrorHandler(shortNumber, shortNumber_ValidationError);
        }

        void shortNumber_ValidationError(object sender, ValidationErrorEventArgs e)
        {
            MessageBox.Show((string)e.Error.ErrorContent, "유효성 검사 실패");
            shortNumber.ToolTip = (string)e.Error.ErrorContent;
        }

        private void earseButton_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            Person person = (Person)view.CurrentItem;

            person.ShortNumber = null;
            person.Name = "";
            person.Phone = "";
            person.Age = null;
            person.Male = null;
        }

        private void prev_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            view.MoveCurrentToPrevious();
            if(view.IsCurrentBeforeFirst)
            {
                view.MoveCurrentToFirst();
            }
        }

        private void next_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            view.MoveCurrentToNext();
            if (view.IsCurrentAfterLast)
            {
                view.MoveCurrentToLast();
            }
        }

        private void removeButton_Click(object sender, RoutedEventArgs e)
        {
            People people = (People)FindResource("people");

            if (listbox.SelectedIndex >= 0)
                people.RemoveAt(listbox.SelectedIndex);
        }

        private void Insert_Click(object sender, RoutedEventArgs e)
        {
            People people = (People)FindResource("people");

            Person newperson = new Person()
            {
                ShortNumber = per.ShortNumber,
                Name = per.Name,
                Phone = per.Phone,
                Age = per.Age,
                Male = per.Male
            };

            people.Add(newperson);
        }

        //검색
        private void selectButton_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            if (view.Filter == null)
            {
                view.Filter = delegate (object obj)
                {
                    return ((Person)obj).Name == selectName.Text;
                };
            }
            else
            {
                view.Filter = null;
            }
        }
    }
}
