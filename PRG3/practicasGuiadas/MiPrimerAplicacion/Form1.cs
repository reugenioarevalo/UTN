using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MiPrimerAplicacion
{
    public partial class MiPrimeraAplicacion : Form
    {
        public MiPrimeraAplicacion()
        {
            InitializeComponent();
        }

        private void MiPrimeraAplicacion_Load(object sender, EventArgs e)
        {
            MessageBox.Show("Hola ");
        }

        private void btnTocame_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("Pasará a modo Dark");
            //this.BackColor = Color.Black;
            if (txtDescripcion.Text == "")
                txtDescripcion.BackColor = Color.BlueViolet;
            else
                txtDescripcion.BackColor = System.Drawing.SystemColors.Control;
        }

        private void MiPrimeraAplicacion_FormClosed(object sender, FormClosedEventArgs e)
        {
            MessageBox.Show("Chaucito!!! ");
        }

        private void MiPrimeraAplicacion_Click(object sender, EventArgs e)
        {
            MouseEventArgs click = (MouseEventArgs)e;
            if (click.Button == MouseButtons.Left)
                MessageBox.Show("Precionó el boton izquierdo.", "Atención");
            else if (click.Button == MouseButtons.Right)
                MessageBox.Show("Presionó el botón derecho!", "Atención");
            else if (click.Button == MouseButtons.Middle)
                MessageBox.Show("Presionó el botón del Centro", "Atención");

        }

        private void lblEtiqueta_Click(object sender, EventArgs e)
        {

        }

        private void lblEtiqueta_MouseMove(object sender, MouseEventArgs e)
        {
            lblEtiqueta.BackColor = Color.BurlyWood;
            lblEtiqueta.Cursor = Cursors.Hand;
        }

        private void lblEtiqueta_MouseLeave(object sender, EventArgs e)
        {
            lblEtiqueta.BackColor = System.Drawing.Color.DodgerBlue;
            //lblEtiqueta.BackColor = System.Drawing.SystemColors.Control;
            lblEtiqueta.Cursor = Cursors.Arrow;
        }

        private void txtDescripcion_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < 48 || e.KeyChar > 59) && e.KeyChar != 8)
                e.Handled = true;
        }

        private void txtDetalle_Leave(object sender, EventArgs e)
        {
            MessageBox.Show("Tiene: " + txtDetalle.Text.Length + " Caracteres.");
        }
    }
}
