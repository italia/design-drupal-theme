(function (Drupal, once) {
  Drupal.behaviors.speechSynthesisUtterance = {
    attach(context, settings) {
      once(
        'speechSynthesisUtterance',
        '#it-block-italiagov-content',
        context
      ).forEach(function (element) {
        const lang = navigator.language;
        const voiceIndex = 1;
        const rate = 0.9;

        const speak = async (text) => {
          if (!speechSynthesis) {
            return;
          }
          const message = new SpeechSynthesisUtterance(text);
          message.voice = await chooseVoice();
          message.rate = rate;
          speechSynthesis.speak(message);
        };

        const getVoices = () => {
          return new Promise((resolve) => {
            let voices = speechSynthesis.getVoices();
            if (voices.length) {
              resolve(voices);
              return;
            }
            speechSynthesis.onvoiceschanged = () => {
              voices = speechSynthesis.getVoices();
              resolve(voices);
            };
          });
        };

        const chooseVoice = async () => {
          const voices = (await getVoices()).filter(
            (voice) => voice.lang === lang
          );

          return new Promise((resolve) => {
            resolve(voices[voiceIndex]);
          });
        };

        const extractTextFromNode = (el) => {
          const a = [];
          const walk = document.createTreeWalker(
            el,
            NodeFilter.SHOW_TEXT,
            null,
            false
          );
          let n;
          while ((n = walk.nextNode())) {
            a.push(n.textContent);
          }
          return a.join(' ');
        };

        // SETTING THE PLAY CONTROL
        // First we get the value of the textarea or document
        document
          .getElementById('it-share-action-speak')
          .addEventListener('click', () => {
            const classToRead = document.getElementById(
              'it-share-action-speak'
            ).dataset.biRead;
            const elementToRead = document.querySelector(`.${classToRead}`);
            speak(extractTextFromNode(elementToRead));
          });

        /* // Optionals // TODO more tag?
        // PAUSE
        document.getElementById("pause").addEventListener("click", () => {
          // Pause the speechSynthesis instance
          window.speechSynthesis.pause();
        });

        // RESUME
        document.getElementById("resume").addEventListener("click", () => {
          // Resume the paused speechSynthesis instance
          window.speechSynthesis.resume();
        });

        // CANCEL
        document.querySelector("cancel").addEventListener("click", () => {
          // Cancel the speechSynthesis instance
          window.speechSynthesis.cancel();
        });
        // End optionals */
      });
    },
  };
})(Drupal, once);
