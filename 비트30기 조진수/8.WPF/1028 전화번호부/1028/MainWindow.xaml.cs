using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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

namespace _1028
{
   

    //public class People : List<Person>
    public class People : ObservableCollection<Person>
    {
        public People()
        {
            Add(new Person() { ShortNumber = 0, Male = true, Name = "홍길동", Phone = "010-1111-1234", Age = 21 });
            Add(new Person() { ShortNumber = 1, Male = true, Name = "일지매", Phone = "010-2222-1234", Age = 22 });
            Add(new Person() { ShortNumber = 2, Male = false, Name = "임꺽정", Phone = "010-3333-1234", Age = 23 });
        }
    }

    public partial class MainWindow : Window
    {
        private People people = new People();
        private Person per;

        public MainWindow()
        {
            InitializeComponent();

            per = people[0];

            UpdateData();

            UpdateListBox();
        }

        #region Update info
        private void UpdateNameToUi()
        {
            if (per == null)
            {
                name.Text = "";
                nameLabel.Content = "";
            }
            else
            {
                name.Text = per.Name;
                nameLabel.Content = per.Name;
            }
        }
        private void UpdatePhoneToUi()
        {
            if (per == null)
            {
                phone.Text = "";
                phoneLabel.Content = "";
            }
            else
            {
                phone.Text = per.Phone;
                phoneLabel.Content = per.Phone;
            }
        }
        private void UpdateAgeToUi()
        {
            if (per == null)
            {
                age.Text = "";
                ageLabel.Content = "";
            }
            else
            {
                age.Text = per.Age.ToString();
                ageLabel.Content = per.Age;
            }
        }

        private void name_TextChanged(object sender, TextChangedEventArgs e)
        {
            //per.Name = name.Text;
        }
        private void phone_TextChanged(object sender, TextChangedEventArgs e)
        {
            //per.Phone = phone.Text;
        }
        private void age_TextChanged(object sender, TextChangedEventArgs e)
        {
            //per.Age = int.Parse(age.Text);
        }

        private void UpdateData()
        {
            UpdateNameToUi();
            UpdatePhoneToUi();
            UpdateAgeToUi();
        }
        #endregion
        
        #region 리스트박스핸들러
        private void UpdateListBox()
        {
            listbox.Items.Clear();

            foreach (Person per in people)
                listbox.Items.Add(per.ToString());
        }

        private void listbox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(listbox.SelectedIndex >= 0)
            {
                per = people[listbox.SelectedIndex];
                UpdateData();
            }
        }
        #endregion

        #region 버튼핸들러
        private void addButton_Click(object sender, RoutedEventArgs e)
        {
            if (name.Text == "" || phone.Text == "" || age.Text == "")
                return;

            
            people.Add(new Person() { Name = name.Text, Phone = phone.Text, Age = int.Parse(age.Text) });

            per = people[people.Count - 1];
            UpdateData();

            UpdateListBox();
        }
        private void removeButton_Click(object sender, RoutedEventArgs e)
        {
            if(listbox.SelectedIndex >= 0)
            {
                people.RemoveAt(listbox.SelectedIndex);

                if (people.Count == 0)
                    per = null;
                else
                    per = people[0];

                UpdateData();
                UpdateListBox();
            }
        }
        private void updateButton_Click(object sender, RoutedEventArgs e)
        {
            if (name.Text == "" || phone.Text == "" || age.Text == "")
                return;

            per.Name = name.Text;
            per.Phone = phone.Text;
            per.Age = int.Parse(age.Text);

            UpdateData();
            UpdateListBox();
        }
        #endregion
    }
}
