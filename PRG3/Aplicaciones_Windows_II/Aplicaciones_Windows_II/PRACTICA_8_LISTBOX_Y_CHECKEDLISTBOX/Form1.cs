using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PRACTICA_8_LISTBOX_Y_CHECKEDLISTBOX
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            chLstBxItems.Items.Add("Diez");
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnMover_Click(object sender, EventArgs e)
        {
            if(chLstBxItems.CheckedItems.Count > 0)
            {
                lstBxLista.Items.Clear();
                foreach(string item in chLstBxItems.CheckedItems)
                {
                    lstBxLista.Items.Add(item.ToString());
                }
                for (int i =0; i < chLstBxItems.Items.Count; i++)
                {
                    chLstBxItems.SetItemChecked(i, false);

                }
            }
        }
    }
}
