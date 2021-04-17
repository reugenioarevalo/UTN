namespace PRACTICA_6_RADIOBUTTON_CHECKBOX
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lblNombre = new System.Windows.Forms.Label();
            this.lblSalida = new System.Windows.Forms.Label();
            this.txtSalida = new System.Windows.Forms.TextBox();
            this.chbxProgramador = new System.Windows.Forms.CheckBox();
            this.lblProgramador = new System.Windows.Forms.Label();
            this.rdHombre = new System.Windows.Forms.RadioButton();
            this.rdoMujer = new System.Windows.Forms.RadioButton();
            this.btnOk = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(139, 48);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(295, 20);
            this.txtNombre.TabIndex = 0;
            this.txtNombre.Validated += new System.EventHandler(this.txtNombre_Validating);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rdoMujer);
            this.groupBox1.Controls.Add(this.rdHombre);
            this.groupBox1.ForeColor = System.Drawing.Color.LightCoral;
            this.groupBox1.Location = new System.Drawing.Point(74, 146);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(360, 43);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Sexo";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // lblNombre
            // 
            this.lblNombre.AutoSize = true;
            this.lblNombre.Location = new System.Drawing.Point(80, 48);
            this.lblNombre.Name = "lblNombre";
            this.lblNombre.Size = new System.Drawing.Size(44, 13);
            this.lblNombre.TabIndex = 2;
            this.lblNombre.Text = "Nombre";
            // 
            // lblSalida
            // 
            this.lblSalida.AutoSize = true;
            this.lblSalida.Location = new System.Drawing.Point(71, 224);
            this.lblSalida.Name = "lblSalida";
            this.lblSalida.Size = new System.Drawing.Size(36, 13);
            this.lblSalida.TabIndex = 4;
            this.lblSalida.Text = "Salida";
            // 
            // txtSalida
            // 
            this.txtSalida.Location = new System.Drawing.Point(74, 250);
            this.txtSalida.Multiline = true;
            this.txtSalida.Name = "txtSalida";
            this.txtSalida.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtSalida.Size = new System.Drawing.Size(360, 132);
            this.txtSalida.TabIndex = 3;
            // 
            // chbxProgramador
            // 
            this.chbxProgramador.AutoSize = true;
            this.chbxProgramador.Checked = true;
            this.chbxProgramador.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chbxProgramador.Location = new System.Drawing.Point(153, 99);
            this.chbxProgramador.Name = "chbxProgramador";
            this.chbxProgramador.Size = new System.Drawing.Size(15, 14);
            this.chbxProgramador.TabIndex = 5;
            this.chbxProgramador.UseVisualStyleBackColor = true;
            // 
            // lblProgramador
            // 
            this.lblProgramador.AutoSize = true;
            this.lblProgramador.Location = new System.Drawing.Point(80, 99);
            this.lblProgramador.Name = "lblProgramador";
            this.lblProgramador.Size = new System.Drawing.Size(67, 13);
            this.lblProgramador.TabIndex = 6;
            this.lblProgramador.Text = "Programador";
            // 
            // rdHombre
            // 
            this.rdHombre.AutoSize = true;
            this.rdHombre.Checked = true;
            this.rdHombre.Location = new System.Drawing.Point(65, 20);
            this.rdHombre.Name = "rdHombre";
            this.rdHombre.Size = new System.Drawing.Size(62, 17);
            this.rdHombre.TabIndex = 0;
            this.rdHombre.TabStop = true;
            this.rdHombre.Text = "Hombre";
            this.rdHombre.UseVisualStyleBackColor = true;
            // 
            // rdoMujer
            // 
            this.rdoMujer.AutoSize = true;
            this.rdoMujer.Location = new System.Drawing.Point(230, 19);
            this.rdoMujer.Name = "rdoMujer";
            this.rdoMujer.Size = new System.Drawing.Size(51, 17);
            this.rdoMujer.TabIndex = 1;
            this.rdoMujer.Text = "Mujer";
            this.rdoMujer.UseVisualStyleBackColor = true;
            // 
            // btnOk
            // 
            this.btnOk.Location = new System.Drawing.Point(506, 43);
            this.btnOk.Name = "btnOk";
            this.btnOk.Size = new System.Drawing.Size(90, 23);
            this.btnOk.TabIndex = 7;
            this.btnOk.Text = "OK";
            this.btnOk.UseVisualStyleBackColor = true;
            this.btnOk.Click += new System.EventHandler(this.btnOk_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(659, 408);
            this.Controls.Add(this.btnOk);
            this.Controls.Add(this.lblProgramador);
            this.Controls.Add(this.chbxProgramador);
            this.Controls.Add(this.lblSalida);
            this.Controls.Add(this.txtSalida);
            this.Controls.Add(this.lblNombre);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.txtNombre);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label lblNombre;
        private System.Windows.Forms.Label lblSalida;
        private System.Windows.Forms.TextBox txtSalida;
        private System.Windows.Forms.CheckBox chbxProgramador;
        private System.Windows.Forms.Label lblProgramador;
        private System.Windows.Forms.RadioButton rdoMujer;
        private System.Windows.Forms.RadioButton rdHombre;
        private System.Windows.Forms.Button btnOk;
    }
}

