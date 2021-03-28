using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace tp1
{
    public partial class TP1 : Form
    {
        public TP1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Hola " + txtNombre.Text );
        }

        private void TP1_Load(object sender, EventArgs e)
        {
            cboColores.Items.Add("Rojo");
            cboColores.Items.Add("Azul");
            cboColores.Items.Add("Verde");
        }

        private void txtNombre_TextChanged(object sender, EventArgs e)
        {

            MessageBox.Show("texto camibio ");
        }

    }
}
