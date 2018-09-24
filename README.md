# RobotController

tid er i sekunder (kan ikke være mindre end 0.001)

Liste over kommandoer:
- DrejTilHoejre(tid)
- DrejTilVenstre(tid)
- KoerFremad(tid)
- KoerBagud(tid)
- Pause(tid)
- Stop()

Advancerede kommandoer:
- TankController(retning) [Retning kan kun være mellem 0 - 100]
- SetRetning(motorRetningA, motorRetningB)
- Koer(hastighedA, hastighedB) [Hastighed kan kun være mellem 0 - 255]
- kalibrerLys()
