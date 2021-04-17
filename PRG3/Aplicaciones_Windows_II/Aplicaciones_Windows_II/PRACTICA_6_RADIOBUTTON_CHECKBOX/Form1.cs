using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PRACTICA_6_RADIOBUTTON_CHECKBOX
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //deshabilito el boton ok.
            btnOk.Enabled = false;
        }
 
        private void ValidarOK()
        {
            //habilita el Boton siempre y cuando txtNombre tenga datos.
            btnOk.Enabled = (txtNombre.BackColor != Color.Red);
        }

        private void txtNombre_Validating(object sender, EventArgs e)
        {
            TextBox tb= (TextBox)sender;
            if (tb.Text.Length == 0)
                tb.BackColor = Color.Red;
            else
                tb.BackColor = System.Drawing.SystemColors.Window;
            ValidarOK();
        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            //no valido datos ya que si el boton esta habiitado
            //es porque paso el evento validatting del nombre
            String salida; //declaro una variable para arma l asalida
            salida = "NOmbre: " + txtNombre.Text + "\r\n";
            salida += "Ocupación: " + (string)(chbxProgramador.Checked ? "Programador" : "NO es programador");
            salida += "\r\n" + "Sexo: "+ (string)(rdHombre.Checked?"Hombre ":"Mujer")+"\r\n";
            //vuelvo la salida al textbox salida.
            txtSalida.Text = salida;



        }
    }
}
