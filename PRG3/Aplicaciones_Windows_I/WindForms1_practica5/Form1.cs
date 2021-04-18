using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindForms1_practica5
{
    public partial class frmPractica5 : Form
    {
        public frmPractica5()
        {
            InitializeComponent();
        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            if (txtApellido.Text == ""){ 
                txtApellido.BackColor = Color.Red;
            }else{
                txtApellido.BackColor = System.Drawing.SystemColors.Control;
                txtResultado.Text = "APELLIDO Y NOMBRE:" + txtApellido.Text;
            }
            if (txtNombre.Text == ""){
                txtNombre.BackColor = Color.Red;
            }else{
                txtNombre.BackColor = System.Drawing.SystemColors.Control;
                txtResultado.Text = "APELLIDO Y NOMBRE:" + txtApellido.Text +" " + txtNombre.Text +
                "\r\n";
            }
            if (txtEdad.Text == ""){
                txtEdad.BackColor = Color.Red;
            }else{
                txtEdad.BackColor = System.Drawing.SystemColors.Control;
                txtResultado.Text = "APELLIDO Y NOMBRE:" + txtApellido.Text +" " + txtNombre.Text +
                "\r\n" + "EDAD: " + txtEdad.Text + "\r\n";
            }
            if (txtDireccion.Text == ""){
                txtDireccion.BackColor = Color.Red;
            }else{ 
                txtDireccion.BackColor = System.Drawing.SystemColors.Control; 
                txtResultado.Text = "APELLIDO Y NOMBRE:" + txtApellido.Text +" " + txtNombre.Text +
                 "\r\n" + "EDAD: " + txtEdad.Text + "\r\n" + "DIRECCION: " + txtDireccion.Text;
            }
           
        }

        private void txtEdad_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < 48 || e.KeyChar > 59) && e.KeyChar != 8)
                e.Handled = true;
        }

        private void btnCancelar_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Ud Cerró la aplicacion ", "Anteción");
            this.Close();
           
        }
    }
}
