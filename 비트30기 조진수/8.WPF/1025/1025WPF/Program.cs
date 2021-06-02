using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace _1025WPF
{
    class MyWindow : Window
    {
        public MyWindow()
        {
            Button btn = new Button();
            btn.Click += Btn_Click;
            btn.Width = 100;
            btn.Height = 25;
            btn.Content = "클릭";

            AddChild(btn);

            Title = "WPF Windows";
        }

        private void Btn_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("버튼클릭");
        }
    }
    class Program : Application
    {
        [STAThread]
        static void Main(string[] args)
        {
            //MessageBox.Show("First WPF");
            Program pro = new Program();
            pro.Startup += pro.My_StartUp;
            pro.Run();
        }

        void My_StartUp(object sender, StartupEventArgs e)
        {
            MyWindow window = new MyWindow();
            window.Show();
        }
    }
}
