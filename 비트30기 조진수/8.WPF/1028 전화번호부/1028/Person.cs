using System;
using System.ComponentModel;
using System.Globalization;
using System.Windows.Controls;
using System.Windows.Data;

namespace _1028
{
    public class Person : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private string name;
        public string Name
        {
            get { return name; }
            set
            {
                name = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Name"));
            }
        }
        private string phone;
        public string Phone
        {
            get { return phone; }
            set
            {
                phone = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Phone"));
            }
        }
        private int? age;
        public int? Age
        {
            get { return age; }
            set
            {
                age = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Age"));
            }
        }
        private bool? male;
        public bool? Male
        {
            get { return male; }
            set
            {
                male = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Male"));
            }
        }
        private int? shortNmber;
        public int? ShortNumber
        {
            get { return shortNmber; }
            set
            {
                shortNmber = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("ShortNumber"));
            }
        }

        

        public override string ToString()
        {
            return ShortNumber + " : " +Name + " : " + Phone + " : " + Age + " : " + Male;
        }
    }



    #region 형식변환
    public class ShortNumberValidationRule : ValidationRule
    {
        public int Min { get; set; }
        public int Max { get; set; }

        public override ValidationResult Validate(object value, System.Globalization.CultureInfo cultureInfo)
        {
            int number;

            if(!int.TryParse((string)value,out number))
            {
                return new ValidationResult(false, "정수를 입력하세요");
            }

            if(Min <= number && number <=Max)
            {
                return ValidationResult.ValidResult;
            }
            else
            {
                string msg = string.Format("단축 번호는 {0}에서 {1}까지 입력가능합니다.", Min, Max);
                return new ValidationResult(false, msg);
            }
        }
    }

    public class MaleToFemaleConverter : IValueConverter
    {
        //데이터 속성을 UI속성으로 변경할때
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            if (targetType != typeof(bool?))
                return null;

            bool? male = (bool?)value;

            if (male == null)
                return null;
            else
                return !(bool?)value;
        }

        //UI속성을 데이터 속성으로 변경할 때
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            if (targetType != typeof(bool?))
                return null;

            bool? male = (bool?)value;

            if (male == null)
                return null;
            else
                return !(bool?)value;
        }
    }


    //형식변환기 : bool <--> string
    public class BoolToStringConverter : IValueConverter
    {
        //데이터 속성을 UI속성으로 변경할때
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            //if (targetType != typeof(bool?))
            //    return null;

            bool? male = (bool?)value;

            if (male == null)
                return "";
            else if (male == true)
                return "남성";
            else
                return "여성";
        }

        //UI속성을 데이터 속성으로 변경할 때
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            //if (targetType != typeof(bool?))
            //    return null;

            string male = (string)value;

            if (male == "")
                return null;
            else if (male == "남성")
                return true;
            else
                return false;
        }
    }
    #endregion
}
