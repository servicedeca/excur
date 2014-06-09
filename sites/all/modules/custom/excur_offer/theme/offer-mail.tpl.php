<table cellspacing="2" border="1" cellpadding="5" bordercolor="#ccc" width="1200px" height="600px" style='font-family:Arial, Helvetica, sans-serif;
	color:#666;
	font-size:20px;
	text-shadow: 1px 1px 0px #fff;
	background:#eaebec;
	margin:20px;
	border:#ccc 1px solid;
	border-collapse:separate;
	padding:18px;
	border-bottom:1px solid #e0e0e0;
	border-left: 1px solid #e0e0e0;
	background: #fafafa;'>
  <tr style='border-bottom:1px solid #e0e0e0;'>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Voucher #'); ?></p>
    </td>
    <td><p><?php print $offer->oid; ?></p>
    </td>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Date'); ?></p>
    </td>
    <td><p><?php print date('Y-m-d', $offer->created); ?></p>
    </td>
    <td rowspan="2"><p><?php print $logo; ?></p>
    </td>
    <td rowspan="2"><p><?php print $contacts; ?></p>
    </td>
  </tr>
  <tr>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Title'); ?></p>
    </td>
    <td colspan="3"><p><?php print $title; ?></p>
    </td>
  </tr>
  <tr bgcolor="#F5F5F5">
    <td colspan="6"><p><br></p>
    </td>
  </tr>
  <tr>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Excursion'); ?></p>
    </td>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Date'); ?></p>
    </td>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Price'); ?></p>
    </td>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Duration'); ?></p>
    </td>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Language'); ?></p>
    </td>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Country'); ?></p>
    </td>
  </tr>
  <tr>
    <td><p><?php print $offer->nid; ?></p>
    </td>
    <td><p><?php print $offer->date; ?></p>
    </td>
    <td><p><?php print $price . ' ' . $offer->currency; ?></p>
    </td>
    <td><p><?php print $duration; ?></p>
    </td>
    <td><p><?php print $languages; ?></p>
    </td>
    <td><p><?php print $country; ?></p>
    </td>
  </tr>
  <tr bgcolor="#F5F5F5">
    <td colspan="6"><p><br></p>
    </td>
  </tr>
  <tr>
    <td bgcolor="#C3C1C1" align="center" rowspan="2"><p><?php print t('Organizer'); ?></p>
    </td>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Name'); ?></p>
    </td>
    <td colspan="4"><p><?php print $guide_name; ?></p>
    </td>
  </tr>
  <tr>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Contacts'); ?></p>
    </td>
    <td colspan="4"><p><?php print $guide_contacts; ?></p>
    </td>
  </tr>
  <tr>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Venue'); ?></p>
    </td>
    <td colspan="3"><p><?php print $venue; ?></p>
    </td>
    <td bgcolor="#C3C1C1" align="center"><p><?php print t('Time of meeting'); ?></p>
    </td>
    </td>
    <td colspan=""><p><?php print $meeting_time; ?></p>
    </td>
  </tr>
</table>
<p><br></p>