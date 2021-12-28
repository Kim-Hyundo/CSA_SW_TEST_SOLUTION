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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ProstMain.CustomControl
{
    /// <summary>
    /// NumericSpinner.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class NumericSpinner : UserControl
    {
        #region Fields

        public event EventHandler PropertyChanged;
        public event EventHandler ValueChanged;
        #endregion

        public NumericSpinner()
        {
            InitializeComponent();

            tb_main.SetBinding(TextBox.TextProperty, new Binding("Value")
            {
                ElementName = "root_numeric_spinner",
                Mode = BindingMode.TwoWay,
                UpdateSourceTrigger = UpdateSourceTrigger.Default,
            });

            tb_main.SetBinding(TextBox.WidthProperty, new Binding("TextWidthPer") {
                ElementName = "root_numeric_spinner",
                Mode = BindingMode.TwoWay,
                UpdateSourceTrigger = UpdateSourceTrigger.PropertyChanged,
            });

            ButtonColumeDef.SetBinding(Grid.WidthProperty, new Binding("ButtonWidthPer")
            {
                ElementName = "root_numeric_spinner",
                Mode = BindingMode.TwoWay,
                UpdateSourceTrigger = UpdateSourceTrigger.PropertyChanged
            });

            DependencyPropertyDescriptor.FromProperty(TextWidthPerProperty, typeof(NumericSpinner)).AddValueChanged(this, PropertyChanged);
            DependencyPropertyDescriptor.FromProperty(ButtonWidthPerProperty, typeof(NumericSpinner)).AddValueChanged(this, PropertyChanged);
            DependencyPropertyDescriptor.FromProperty(ValueProperty, typeof(NumericSpinner)).AddValueChanged(this, PropertyChanged);
            DependencyPropertyDescriptor.FromProperty(ValueProperty, typeof(NumericSpinner)).AddValueChanged(this, ValueChanged);
            DependencyPropertyDescriptor.FromProperty(DecimalsProperty, typeof(NumericSpinner)).AddValueChanged(this, PropertyChanged);
            DependencyPropertyDescriptor.FromProperty(MinValueProperty, typeof(NumericSpinner)).AddValueChanged(this, PropertyChanged);
            DependencyPropertyDescriptor.FromProperty(MaxValueProperty, typeof(NumericSpinner)).AddValueChanged(this, PropertyChanged);

            PropertyChanged += (x, y) => validate();
        }
        public readonly static DependencyProperty TextWidthPerProperty = DependencyProperty.Register(
            "TextWidthPer",
            typeof(decimal),
            typeof(NumericSpinner),
            new PropertyMetadata(new decimal(84)));

        public decimal TextWidthPer
        {
            get { return (decimal)GetValue(TextWidthPerProperty); }
            set
            {
                SetValue(TextWidthPerProperty, value);
            }
        }
        public readonly static DependencyProperty ButtonWidthPerProperty = DependencyProperty.Register(
    "ButtonWidthPer",
    typeof(decimal),
    typeof(NumericSpinner),
    new PropertyMetadata(new decimal(0)));

        public decimal ButtonWidthPer
        {
            get { return (decimal)GetValue(ButtonWidthPerProperty); }
            set
            {
                SetValue(ButtonWidthPerProperty, value);
            }
        }

        #region ValueProperty

        public readonly static DependencyProperty ValueProperty = DependencyProperty.Register(
            "Value",
            typeof(double),
            typeof(NumericSpinner),
            new PropertyMetadata(0.0));

        public double Value
        {
            get { return (double)GetValue(ValueProperty); }
            set
            {
                if (value < MinValue)
                    value = MinValue;
                if (value > MaxValue)
                    value = MaxValue;
                SetValue(ValueProperty, value);
                if (ValueChanged != null)
                    ValueChanged(this, new EventArgs());
            }
        }


        #endregion

        #region StepProperty

        public readonly static DependencyProperty StepProperty = DependencyProperty.Register(
            "Step",
            typeof(double),
            typeof(NumericSpinner),
            new PropertyMetadata(0.1));

        public double Step
        {
            get { return (double)GetValue(StepProperty); }
            set
            {
                SetValue(StepProperty, value);
            }
        }

        #endregion

        #region DecimalsProperty

        public readonly static DependencyProperty DecimalsProperty = DependencyProperty.Register(
            "Decimals",
            typeof(int),
            typeof(NumericSpinner),
            new PropertyMetadata(2));

        public int Decimals
        {
            get { return (int)GetValue(DecimalsProperty); }
            set
            {
                SetValue(DecimalsProperty, value);
            }
        }

        #endregion

        #region MinValueProperty

        public readonly static DependencyProperty MinValueProperty = DependencyProperty.Register(
            "MinValue",
            typeof(double),
            typeof(NumericSpinner),
            new PropertyMetadata(0.0));

        public double MinValue
        {
            get { return (double)GetValue(MinValueProperty); }
            set
            {
                if (value > MaxValue)
                    MaxValue = value;
                SetValue(MinValueProperty, value);
            }
        }

        #endregion

        #region MaxValueProperty

        public readonly static DependencyProperty MaxValueProperty = DependencyProperty.Register(
            "MaxValue",
            typeof(double),
            typeof(NumericSpinner),
            new PropertyMetadata(10.0));

        public double MaxValue
        {
            get { return (double)GetValue(MaxValueProperty); }
            set
            {
                if (value < MinValue)
                    value = MinValue;
                SetValue(MaxValueProperty, value);
            }
        }

        #endregion

        /// <summary>
        /// Revalidate the object, whenever a value is changed...
        /// </summary>
        private void validate()
        {
            // Logically, This is not needed at all... as it's handled within other properties...
            if (MinValue > MaxValue) MinValue = MaxValue;
            if (MaxValue < MinValue) MaxValue = MinValue;
            if (Value < MinValue) Value = MinValue;
            if (Value > MaxValue) Value = MaxValue;

            Value = Math.Round(Value, Decimals);
        }

        private void cmdUp_Click(object sender, RoutedEventArgs e)
        {
            Value += Step;
        }

        private void cmdDown_Click(object sender, RoutedEventArgs e)
        {
            Value -= Step;
        }

        private void tb_main_Loaded(object sender, RoutedEventArgs e)
        {
            ValueChanged(this, new EventArgs());
            
        }

        private void tb_main_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
