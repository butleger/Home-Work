using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
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

namespace TestWPF
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private String leftOp;
        private String rightOp;
        private String operation;
        public MainWindow()
        {
            InitializeComponent();

            foreach (UIElement el in LayoutRoot.Children )
            {
                if ( el is Button)
                {
                    ((Button)el).Click += buttonClick;
                }
            }
        }

        private void buttonClick(object sender, RoutedEventArgs e)
        {
            String s = (string)((Button)e.OriginalSource).Content;
            textBlock.Text += s;
            Int32 num;
            bool result = Int32.TryParse(s, out num);
            if (result)// if input is button
            {
                if (operation == "")
                {
                    leftOp += s;
                }
                else
                {
                    rightOp += s;
                }
            }
            else // if clicked on +- or some this buttons
            {
                if (s == "=")
                {
                    updateRightOp();
                    textBlock.Text = rightOp.ToString();
                    operation = "";
                }
                else if (s == "CLEAR")
                {
                    leftOp = "";
                    rightOp = "";
                    operation = "";
                    textBlock.Text = "";
                }
                else
                {
                    if (rightOp != "" )
                    {
                        updateRightOp();
                        leftOp = rightOp;
                        rightOp = "";
                    }
                    operation = s;
                }
            }
        }

        private void updateRightOp()
        {
            int num1 = 0;
            int num2 = 0;
            try 
            {
                num1 = Int32.Parse(leftOp);
                num2 = Int32.Parse(rightOp);
            } 
            catch (Exception ex) 
            {
                textBlock.Text = "Fuck you!";
            }

            switch (operation)
            {
                case "+":
                    rightOp = (num1 + num2).ToString();
                    break;
                case "-":
                    rightOp = (num1 - num2).ToString();
                    break;
                case "*":
                    rightOp = (num1 * num2).ToString();
                    break;
                case "/":
                    rightOp = (num1 / num2).ToString();
                    break;
            }
        }
    }
}
