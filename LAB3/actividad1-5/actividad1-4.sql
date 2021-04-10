SELECT 
Clientes.IdCiudad AS ID,
Clientes.RazonSocial, 
TiposDeClientes.Tipo AS Tipo,
Clientes.Cuit,
Clientes.Mail,
Clientes.Telefono,
Clientes.Celular,
Ciudades.Nombre AS Ciudad,
Paises.Nombre AS Pais
FROM Clientes
LEFT JOIN TiposDeClientes  on TiposDeClientes.Id = Clientes.IdTipo
LEFT JOIN Ciudades on Ciudades.Id = Clientes.IdCiudad
LEFT JOIN Paises on Paises.Id = Ciudades.IdPais
