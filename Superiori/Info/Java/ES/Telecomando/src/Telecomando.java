public class Telecomando {
   private boolean acceso = false;
   private int canale;
   private int volume;
   private boolean mute = false;

   private final int VOLUME_MAX;
   private final int CANALE_MAX;

   private final static int DEFAULT_VOLUME = 100;
   private final static int DEFAULT_CANALE = 999;

   public Telecomando(int volume_max, int canale_max) {
      if (volume_max <= 1 || volume_max > DEFAULT_VOLUME) {
         VOLUME_MAX = DEFAULT_VOLUME;
      } else {
         VOLUME_MAX = volume_max;
      }
      if (canale_max <= 1 || canale_max > DEFAULT_CANALE) {
         CANALE_MAX = DEFAULT_CANALE;
      } else {
         CANALE_MAX = canale_max;
      }
   }

   public void setCanale(int canale) {
      if (canale > 0) {
         this.canale = canale;
      } else {
         this.canale = 1;
      }
   }

   public void setVolume(int volume) {
      if (volume > 0) {
         this.volume = volume;
      } else {
         this.volume = 1;
      }
   }

   public void alzaCanale() {
      if (canale < CANALE_MAX)
         canale += 1;
   }

   public void abbassaCanale() {
      if (canale > 0)
         canale -= 1;
   }

   public void alzaVolume() {
      if (volume < VOLUME_MAX)
         volume += 1;
   }

   public void abbassaVolume() {
      if (volume > 0)
         volume -= 1;
   }

   public int getCanale() {
      return canale;
   }

   public int getVolume() {
      return volume;
   }

   public boolean isMuto() {
      return mute;
   }

   public void MuteOn_Off() {
      mute = !mute;
   }

   public void On_Off() {
      acceso = !acceso;
   }

   public boolean isAcceso() {
      return acceso;
   }

   public String toString() {
      return "Acceso: " + acceso + " Volume: " + volume
            + " Canale: " + canale + " Muto: " + mute;
   }
}