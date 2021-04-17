namespace PRACTICA_7_RICHTEXTBOX
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
            this.btnNegrita = new System.Windows.Forms.Button();
            this.lblTamFuente = new System.Windows.Forms.Label();
            this.txtTamTexto = new System.Windows.Forms.TextBox();
            this.rtxtEditor = new System.Windows.Forms.RichTextBox();
            this.btnSubrayado = new System.Windows.Forms.Button();
            this.btnCursiva = new System.Windows.Forms.Button();
            this.btnCentrado = new System.Windows.Forms.Button();
            this.btnGuardar = new System.Windows.Forms.Button();
            this.btnAbrir = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnNegrita
            // 
            this.btnNegrita.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.btnNegrita.Location = new System.Drawing.Point(55, 12);
            this.btnNegrita.Name = "btnNegrita";
            this.btnNegrita.Size = new System.Drawing.Size(75, 23);
            this.btnNegrita.TabIndex = 0;
            this.btnNegrita.Text = "Negrita";
            this.btnNegrita.UseVisualStyleBackColor = true;
            this.btnNegrita.Click += new System.EventHandler(this.btnNegrita_Click);
            // 
            // lblTamFuente
            // 
            this.lblTamFuente.AutoSize = true;
            this.lblTamFuente.Location = new System.Drawing.Point(182, 68);
            this.lblTamFuente.Name = "lblTamFuente";
            this.lblTamFuente.Size = new System.Drawing.Size(82, 13);
            this.lblTamFuente.TabIndex = 1;
            this.lblTamFuente.Text = "Tamaño Fuente";
            // 
            // txtTamTexto
            // 
            this.txtTamTexto.Location = new System.Drawing.Point(270, 65);
            this.txtTamTexto.MaxLength = 3;
            this.txtTamTexto.Name = "txtTamTexto";
            this.txtTamTexto.Size = new System.Drawing.Size(78, 20);
            this.txtTamTexto.TabIndex = 2;
            this.txtTamTexto.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtTamanio_KeyPress);
            this.txtTamTexto.Validated += new System.EventHandler(this.txtTamani_Validated);
            // 
            // rtxtEditor
            // 
            this.rtxtEditor.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.rtxtEditor.Location = new System.Drawing.Point(12, 102);
            this.rtxtEditor.Name = "rtxtEditor";
            this.rtxtEditor.Size = new System.Drawing.Size(573, 217);
            this.rtxtEditor.TabIndex = 3;
            this.rtxtEditor.Text = "";
            this.rtxtEditor.LinkClicked += new System.Windows.Forms.LinkClickedEventHandler(this.rtxtEditor_LinkCliked);
            // 
            // btnSubrayado
            // 
            this.btnSubrayado.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.btnSubrayado.Location = new System.Drawing.Point(200, 12);
            this.btnSubrayado.Name = "btnSubrayado";
            this.btnSubrayado.Size = new System.Drawing.Size(75, 23);
            this.btnSubrayado.TabIndex = 4;
            this.btnSubrayado.Text = "Subrayado";
            this.btnSubrayado.UseVisualStyleBackColor = true;
            this.btnSubrayado.Click += new System.EventHandler(this.btnSubrayado_Click);
            // 
            // btnCursiva
            // 
            this.btnCursiva.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.btnCursiva.Location = new System.Drawing.Point(346, 12);
            this.btnCursiva.Name = "btnCursiva";
            this.btnCursiva.Size = new System.Drawing.Size(75, 23);
            this.btnCursiva.TabIndex = 5;
            this.btnCursiva.Text = "Cursiva";
            this.btnCursiva.UseVisualStyleBackColor = true;
            this.btnCursiva.Click += new System.EventHandler(this.btnCursiva_Click);
            // 
            // btnCentrado
            // 
            this.btnCentrado.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.btnCentrado.Location = new System.Drawing.Point(463, 12);
            this.btnCentrado.Name = "btnCentrado";
            this.btnCentrado.Size = new System.Drawing.Size(75, 23);
            this.btnCentrado.TabIndex = 6;
            this.btnCentrado.Text = "Centrado";
            this.btnCentrado.UseVisualStyleBackColor = true;
            this.btnCentrado.Click += new System.EventHandler(this.btnCentrado_Click);
            // 
            // btnGuardar
            // 
            this.btnGuardar.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.btnGuardar.Location = new System.Drawing.Point(207, 335);
            this.btnGuardar.Name = "btnGuardar";
            this.btnGuardar.Size = new System.Drawing.Size(75, 23);
            this.btnGuardar.TabIndex = 7;
            this.btnGuardar.Text = "Guardar";
            this.btnGuardar.UseVisualStyleBackColor = true;
            this.btnGuardar.Click += new System.EventHandler(this.btnGuardar_Click);
            // 
            // btnAbrir
            // 
            this.btnAbrir.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.btnAbrir.Location = new System.Drawing.Point(346, 335);
            this.btnAbrir.Name = "btnAbrir";
            this.btnAbrir.Size = new System.Drawing.Size(75, 23);
            this.btnAbrir.TabIndex = 8;
            this.btnAbrir.Text = "Abrir";
            this.btnAbrir.UseVisualStyleBackColor = true;
            this.btnAbrir.Click += new System.EventHandler(this.btnAbrir_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(597, 387);
            this.Controls.Add(this.btnAbrir);
            this.Controls.Add(this.btnGuardar);
            this.Controls.Add(this.btnCentrado);
            this.Controls.Add(this.btnCursiva);
            this.Controls.Add(this.btnSubrayado);
            this.Controls.Add(this.rtxtEditor);
            this.Controls.Add(this.txtTamTexto);
            this.Controls.Add(this.lblTamFuente);
            this.Controls.Add(this.btnNegrita);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnNegrita;
        private System.Windows.Forms.Label lblTamFuente;
        private System.Windows.Forms.TextBox txtTamTexto;
        private System.Windows.Forms.RichTextBox rtxtEditor;
        private System.Windows.Forms.Button btnSubrayado;
        private System.Windows.Forms.Button btnCursiva;
        private System.Windows.Forms.Button btnCentrado;
        private System.Windows.Forms.Button btnGuardar;
        private System.Windows.Forms.Button btnAbrir;
    }
}

