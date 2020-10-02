<?php
    $trovata = null;
    if (isset($_POST["passwd"]))
    {
        $trovata = false;
        $file = fopen("file_passwd.txt", "r");

        $passwd = null;
        while(!feof($file))
        {
            fscanf($file, "%s", $passwd);
            if (strcmp($_POST["passwd"], $passwd) == 0)
            {
                $trovata = true;
                break;
            }
        }
    }
?>
<!DOCTYPE html>
<html lang="it">
    <head>
        <meta charset="utf-8" />
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.1/css/bulma.min.css">
        <style>
            .footer
            {
                background-color: #EEEEEE;
            }

            .copyleft
            {
                display:inline-block;
                transform: rotate(180deg);
            }
        </style>
    </head>
    <body>
        <section class="section">
            <form class="container" action method="POST">
                <div class="field">
                    <input type="text" class="input is-primary" name="passwd" placeholder="Inserisci qui la tua password" />
                </div>
                <div class="control">
                    <button type="submit" class="button is-success">Cerca</button>
                </div>
            </form>
        </section>
        <section class="section">
            <div class="container">
            <?php
                if (!is_null($trovata))
                {
                    if ($trovata)
                    {
                        echo "<div class='notification is-danger'>";
                        echo "<h5 class='title is-5'>Password trovata</h5>";
                        echo "</div>";
                    }
                    else
                    {
                        echo "<div class='notification is-success'>";
                        echo "<h5 class='title is-5'>Password non trovata</h5>";
                        echo "</div>";
                    }
                }
            ?>
            </div>
        </section>
        <footer class="footer">
            <div class="content">
                <div class="columns">
                    <div class="column is-3">
                        <h5 class="title is-5">Wants C version?</h5>
                        <a href="https://github.com/J-Dany/IsYourPasswordTheMostUsed">Check GitHub</a>
                    </div>
                    <div class="column is-9">
                        <h5>Copyleft<span class="copyleft">&copy;</span> by Daniele Castiglia</h5>
                    </div>
                </div>
            </div>
        </footer>
    </body>
</html>