(function () {
  'use strict';

  if ('speechSynthesis' in window) {
    // First we initialize new SpeechSynthesisUtterance object
    let tts    = new SpeechSynthesisUtterance();

    // Setting the Speech Language
    // lang: If unset, the app's (i.e. the <html> lang value) lang will be used, or the user-agent default if that is unset too.
    tts.lang   = 'it-IT';

    let speechvoices = []; // global array of available voices

    // To get the list of voices using getVoices() function
    speechvoices = window.speechSynthesis.getVoices();
    tts.voice  = voices[25];

    // rate
    tts.rate   = 0.9;

    //SETTING THE PLAY CONTROL
    //first we get the value of the textarea or document
    document.getElementById("speak").addEventListener("click", () => {
      tts.text = document.getElementById("lines").value;
      //then we implement the speechsynthesis instance
      window.speechSynthesis.speak(tts);
    });

    // optionals // TODO more tag?
    //PAUSE
    document.getElementById("pause").addEventListener("click", () => {
      // Pause the speechSynthesis instance
      window.speechSynthesis.pause();
    });

    //RESUME
    document.getElementById("resume").addEventListener("click", () => {
      // Resume the paused speechSynthesis instance
      window.speechSynthesis.resume();
    });

    //CANCEL
    document.querySelector("cancel").addEventListener("click", () => {
    // Cancel the speechSynthesis instance
      window.speechSynthesis.cancel();
    });
    // end optionals

  }
  else{
    document.write(Drupal.t("Browser not supported"))
  }

})(Drupal);
