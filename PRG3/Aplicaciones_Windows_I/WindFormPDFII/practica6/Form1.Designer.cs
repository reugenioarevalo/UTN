namespace practica6
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
            this.btnOkNombre = new System.Windows.Forms.Button();
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.lblNombre = new System.Windows.Forms.Label();
            this.chkBoxProgramador = new System.Windows.Forms.CheckBox();
            this.lblProgramador = new System.Windows.Forms.Label();
            this.rboxHombre = new System.Windows.Forms.RadioButton();
            this.rbxMujer = new System.Windows.Forms.RadioButton();
            this.lblSalida = new System.Windows.Forms.Label();
            this.txtSalida = new System.Windows.Forms.TextBox();
            this.bgoBoxSexo = new System.Windows.Forms.GroupBox();
            this.bgoBoxSexo.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnOkNombre
            // 
            this.btnOkNombre.Location = new System.Drawing.Point(644, 69);
            this.btnOkNombre.Name = "btnOkNombre";
            this.btnOkNombre.Size = new System.Drawing.Size(80, 22);
            this.btnOkNombre.TabIndex = 0;
            this.btnOkNombre.Text = "&Ok";
            this.btnOkNombre.UseVisualStyleBackColor = true;
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(175, 69);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(402, 20);
            this.txtNombre.TabIndex = 1;
            // 
            // lblNombre
            // 
            this.lblNombre.AutoSize = true;
            this.lblNombre.Location = new System.Drawing.Point(88, 69);
            this.lblNombre.Name = "lblNombre";
            this.lblNombre.Size = new System.Drawing.Size(44, 13);
            this.lblNombre.TabIndex = 2;
            this.lblNombre.Text = "Nombre";
            // 
            // chkBoxProgramador
            // 
            this.chkBoxProgramador.AutoSize = true;
            this.chkBoxProgramador.Location = new System.Drawing.Point(155, 156);
            this.chkBoxProgramador.Name = "chkBoxProgramador";
            this.chkBoxProgramador.Size = new System.Drawing.Size(15, 14);
            this.chkBoxProgramador.TabIndex = 3;
            this.chkBoxProgramador.UseVisualStyleBackColor = true;
            // 
            // lblProgramador
            // 
            this.lblProgramador.AutoSize = true;
            this.lblProgramador.Location = new System.Drawing.Point(88, 156);
            this.lblProgramador.Name = "lblProgramador";
            this.lblProgramador.Size = new System.Drawing.Size(67, 13);
            this.lblProgramador.TabIndex = 4;
            this.lblProgramador.Text = "Porgramador";
            // 
            // rboxHombre
            // 
            this.rboxHombre.AutoSize = true;
            this.rboxHombre.ForeColor = System.Drawing.Color.Black;
            this.rboxHombre.Location = new System.Drawing.Point(43, 16);
            this.rboxHombre.Name = "rboxHombre";
            this.rboxHombre.Size = new System.Drawing.Size(62, 17);
            this.rboxHombre.TabIndex = 5;
            this.rboxHombre.TabStop = true;
            this.rboxHombre.Text = "Hombre";
            this.rboxHombre.UseVisualStyleBackColor = true;
            // 
            // rbxMujer
            // 
            this.rbxMujer.AutoSize = true;
            this.rbxMujer.ForeColor = System.Drawing.Color.Black;
            this.rbxMujer.Location = new System.Drawing.Point(309, 16);
            this.rbxMujer.Name = "rbxMujer";
            this.rbxMujer.Size = new System.Drawing.Size(51, 17);
            this.rbxMujer.TabIndex = 6;
            this.rbxMujer.TabStop = true;
            this.rbxMujer.Text = "Mujer";
            this.rbxMujer.UseVisualStyleBackColor = true;
            // 
            // lblSalida
            // 
            this.lblSalida.AutoSize = true;
            this.lblSalida.Location = new System.Drawing.Point(85, 253);
            this.lblSalida.Name = "lblSalida";
            this.lblSalida.Size = new System.Drawing.Size(36, 13);
            this.lblSalida.TabIndex = 8;
            this.lblSalida.Text = "Salida";
            // 
            // txtSalida
            // 
            this.txtSalida.Location = new System.Drawing.Point(84, 269);
            this.txtSalida.Multiline = true;
            this.txtSalida.Name = "txtSalida";
            this.txtSalida.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtSalida.Size = new System.Drawing.Size(493, 169);
            this.txtSalida.TabIndex = 7;
            // 
            // bgoBoxSexo
            // 
            this.bgoBoxSexo.Controls.Add(this.rbxMujer);
            this.bgoBoxSexo.Controls.Add(this.rboxHombre);
            this.bgoBoxSexo.ForeColor = System.Drawing.Color.Tomato;
            this.bgoBoxSexo.Location = new System.Drawing.Point(84, 185);
            this.bgoBoxSexo.Name = "bgoBoxSexo";
            this.bgoBoxSexo.Size = new System.Drawing.Size(493, 50);
            this.bgoBoxSexo.TabIndex = 10;
            this.bgoBoxSexo.TabStop = false;
            this.bgoBoxSexo.Text = "Sexo";
            this.bgoBoxSexo.Enter += new System.EventHandler(this.bgoBoxSexo_Enter);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.bgoBoxSexo);
            this.Controls.Add(this.lblSalida);
            this.Controls.Add(this.txtSalida);
            this.Controls.Add(this.lblProgramador);
            this.Controls.Add(this.chkBoxProgramador);
            this.Controls.Add(this.lblNombre);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.btnOkNombre);
            this.Name = "Form1";
            this.Text = "Form1";
            this.bgoBoxSexo.ResumeLayout(false);
            this.bgoBoxSexo.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnOkNombre;
        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.Label lblNombre;
        private System.Windows.Forms.CheckBox chkBoxProgramador;
        private System.Windows.Forms.Label lblProgramador;
        private System.Windows.Forms.RadioButton rboxHombre;
        private System.Windows.Forms.RadioButton rbxMujer;
        private System.Windows.Forms.Label lblSalida;
        private System.Windows.Forms.TextBox txtSalida;
        private System.Windows.Forms.GroupBox bgoBoxSexo;
    }
}

