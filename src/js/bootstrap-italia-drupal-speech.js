(function (Drupal, once) {
  'use strict';

  Drupal.behaviors.speechSynthesisUtterance = {
    attach: function (context, settings) {
      once('speechSynthesisUtterance', '#it-block-italiagov-content', context).forEach(function (element) {

        let lang = navigator.language
        let voiceIndex = 1
        let rate = 0.9

        const speak = async text => {
          if (!speechSynthesis) {
            return
          }
          const message = new SpeechSynthesisUtterance(text)
          message.voice = await chooseVoice()
          message.rate = rate
          speechSynthesis.speak(message)
        }

        const getVoices = () => {
          return new Promise(resolve => {
            let voices = speechSynthesis.getVoices()
            if (voices.length) {
              resolve(voices)
              return
            }
            speechSynthesis.onvoiceschanged = () => {
              voices = speechSynthesis.getVoices()
              resolve(voices)
            }
          })
        }

        const chooseVoice = async () => {
          const voices = (await getVoices()).filter(voice => voice.lang == lang)

          return new Promise(resolve => {
            resolve(voices[voiceIndex])
          })
        }

        const extractTextFromNode = el => {
          let n, a=[], walk=document.createTreeWalker(el,NodeFilter.SHOW_TEXT,null,false);
          while(n=walk.nextNode()) a.push(n.textContent);
          return a.join(' ');
        }

        //SETTING THE PLAY CONTROL
        //first we get the value of the textarea or document
        document.getElementById("it-share-action-speak").addEventListener("click", () => {
          let classToRead = document.getElementById("it-share-action-speak").dataset.biRead;
          let elementToRead = document.querySelector('.'+classToRead);
          speak(extractTextFromNode(elementToRead));
        });

/*        // optionals // TODO more tag?
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
        // end optionals*/

      });
    }
  };

})(Drupal, once);
