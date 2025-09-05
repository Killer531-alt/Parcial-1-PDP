estudiantes = [
    {"nombre": "Carlos", "nota": 85},
    {"nombre": "Ana", "nota": 90},
    {"nombre": "Pedro", "nota": 85},
    {"nombre": "Lucia", "nota": 95}
]

for i in range(len(estudiantes)):
    for j in range(len(estudiantes) - i - 1):
        if (estudiantes[j]["nota"] < estudiantes[j+1]["nota"]) or \
           (estudiantes[j]["nota"] == estudiantes[j+1]["nota"] and 
            estudiantes[j]["nombre"] > estudiantes[j+1]["nombre"]):
            # Intercambio
            estudiantes[j], estudiantes[j+1] = estudiantes[j+1], estudiantes[j]

for e in estudiantes:
    print(f"{e['nombre']} - {e['nota']}")
